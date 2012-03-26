/*	Oscar, a hardware abstraction framework for the LeanXcam and IndXcam.
	Copyright (C) 2008 Supercomputing Systems AG
	
	This library is free software; you can redistribute it and/or modify it
	under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation; either version 2.1 of the License, or (at
	your option) any later version.
	
	This library is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser
	General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License
	along with this library; if not, write to the Free Software Foundation,
	Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef OSCAR_INCLUDE_ERROR_H_
#define OSCAR_INCLUDE_ERROR_H_

/* OscFunction[Finally|Catch|End]: Declare a function using these macros to use the Osc(Fail|Assert|Call)* error handling macros. */
/*! @brief Use this macro to declare a function. */
#ifdef __cplusplus
#define OscFunctionDeclare(name, ...) \
	OSC_ERR name(__VA_ARGS__);

#else
#define OscFunctionDeclare(name, args ...) \
	OSC_ERR name(args);

#endif /* __cplusplus */




#ifdef __cplusplus

#define OscFunction(name, ...) \
	OSC_ERR name(__VA_ARGS__) { \
		struct { \
			OSC_ERR error, status; \
			bool caught: 1; \
			uint32_t stage: 31; \
		} _osc_internal_state_ = { \
			/*.error =*/ SUCCESS, \
			/*.status =*/ SUCCESS, \
			/*.caught =*/ false, \
			/*.stage =*/ 0 \
		}; \
	goto _osc_internal_top_; \
	_osc_internal_top_: \
		if (({ \
			bool res = _osc_internal_state_.stage < 1; \
			if (res) \
				_osc_internal_state_.stage = 1; \
			res; \
		})) {

#else

#define OscFunction(name, args ...) \
	OSC_ERR name(args) { \
		struct { \
			OSC_ERR error, status; \
			bool caught: 1; \
			uint32_t stage: 31; \
		} _osc_internal_state_ = { \
			.error = SUCCESS, \
			.status = SUCCESS, \
			.caught = false, \
			.stage = 0 \
		}; \
	goto _osc_internal_top_; \
	_osc_internal_top_: \
		if (({ \
			bool res = _osc_internal_state_.stage < 1; \
			if (res) \
				_osc_internal_state_.stage = 1; \
			res; \
		})) {
#endif /* __cplusplus */



// FIXME: Too much redundancy between this and the next macro.
#define OscFunctionCatch(e) \
		} else if (({ \
			bool res = false; \
			if (_osc_internal_state_.stage < 2) { \
				OSC_ERR const errs[] = { e }; \
				res = ARR_LENGTH(errs) == 0; \
				for (int i = 0; !res && i < ARR_LENGTH(errs); i += 1) \
					res = errs[i] == _osc_internal_state_.error; \
				if (res) { \
					_osc_internal_state_.stage = 2; \
					_osc_internal_state_.caught = true; \
				} \
			} \
			res; \
		})) {

#define OscFunctionFail(e) \
		} else if (({ \
			bool res = false; \
			if (_osc_internal_state_.stage < 3) { \
				OSC_ERR const errs[] = { e }; \
				res = ARR_LENGTH(errs) == 0; \
				for (int i = 0; !res && i < ARR_LENGTH(errs); i += 1) \
					res = errs[i] == _osc_internal_state_.error; \
				if (res) \
					_osc_internal_state_.stage = 3; \
			} \
			res; \
		})) {



#define OscFunctionFinally() \
		} \
		if (({ \
			bool res = _osc_internal_state_.stage < 4; \
			if (res) \
				_osc_internal_state_.stage = 4; \
			res; \
		})) {

#define OscFunctionEnd() \
		} \
		if (_osc_internal_state_.caught) \
			return SUCCESS; \
		return _osc_internal_state_.error; \
	}



#ifdef __cplusplus
#define OscMark_format(fmt, ...) OscLog(ERROR, "%s: %s(): Line %d " fmt "\n", __FILE__, __FUNCTION__, __LINE__, ## __VA_ARGS__)
#else
#define OscMark_format(fmt, args ...) OscLog(ERROR, "%s: %s(): Line %d " fmt "\n", __FILE__, __FUNCTION__, __LINE__, ## args)
#endif /* __cplusplus */


/* OscMark[_m](): Macros to log a line whenever a source code line is hit. m allows a custom message to be passed. */
/*! @brief Log a marker with a default message whenever a source code line is hit. */
#define OscMark() OscMark_format("")

/*! @brief Log a marker with a custom message whenever a source code line is hit */
#ifdef __cplusplus
#define OscMark_m(m, ...) OscMark_format(": " m, ## __VA_ARGS__)
#else
#define OscMark_m(m, args ...) OscMark_format(": " m, ## args)
#endif /* __cplusplus */


/* OscFail_[e](s|m)(): Macros to abort the current function and execute the exception handler. e is to pass a custom error code. s is not print a message. m is to print a custom message. */
/*! @brief Abort the current function and jump to the exception handler after 'fail:'. */
#define OscFail_es(e) \
	{ \
		_osc_internal_state_.error = e; \
		_osc_internal_state_.caught = false; \
		goto _osc_internal_top_; \
	}

/*! @brief Abort the current function while printing a custom error mesage and jump to the exception handler after 'fail:'. */

#ifdef __cplusplus
#define OscFail_em(e, m, ...) \
	{ \
		OscMark_m(m, ## __VA_ARGS__); \
		OscFail_es(e); \
	}
#else
#define OscFail_em(e, m, args ...) \
	{ \
		OscMark_m(m, ## args); \
		OscFail_es(e); \
	}
#endif /* __cplusplus */


/*! @brief Abort the current function with a custom error code and jump to the exception handler after 'fail:'. */
#define OscFail_e(e) OscFail_es(e)

/*! @brief Abort the current function and jump to the exception handler after 'fail:'. */
#define OscFail_s() OscFail_es(-EGENERAL)

#define OscFail() OscFail_e(-EGENERAL)

/*! @brief Abort the current function with a custom error code while printing a custom error mesage and jump to the exception handler after 'fail:'. */

#ifdef __cplusplus
#define OscFail_m(m, ...) OscFail_em(-EGENERAL, m, ## __VA_ARGS__)
#else
#define OscFail_m(m, args ...) OscFail_em(-EGENERAL, m, ## args)
#endif /* __cplusplus */

/* OscAssert_[e][s|m](): Macros to check an assertion and abort the current function and execute the exception handler on failure. e is to pass a custom error code. s is not print a message. m is to print a custom message. By defualt a general message is printed. */
/*! @brief Check a condition and abort the current function. */
#define OscAssert_es(expr, e) \
	{ \
		if (!(expr)) \
			OscFail_es(e) \
	}

/*! @brief Check a condition and abort the current function while printing a default message. */
#define OscAssert_e(expr, e) \
	{ \
		if (!(expr)) \
			OscFail_e(e); \
	}

/*! @brief Check a condition and abort the current function while printing a custom message. */

#ifdef __cplusplus
#define OscAssert_em(expr, e, m, ...) \
	{ \
		if (!(expr)) \
			OscFail_em(e, m, ## __VA_ARGS__); \
	}
#else
#define OscAssert_em(expr, e, m, args ...) \
	{ \
		if (!(expr)) \
			OscFail_em(e, m, ## args); \
	}
#endif /* __cplusplus */


/* @brief Assert without setting _osc_internal_state_ */

#ifdef __cplusplus
#define OscAssert_w(expr, m, ...)  \
	{ \
		if (!(expr)) { \
			OscMark_format(m, ## __VA_ARGS__); \
			return(EASSERT); \
		} \
	}
#else
#define OscAssert_w(expr, m, args ...)  \
	{ \
		if (!(expr)) { \
			OscMark_format(m, ## args); \
			return(EASSERT); \
		} \
	}
#endif /* __cplusplus */

/*! @brief Check a condition and abort the current function with a custom error code. */
#define OscAssert_s(expr) OscAssert_es(expr, -EASSERT)

/*! @brief Check a condition and abort the current function with a custom error code while printing a default message. */
#define OscAssert(expr) OscAssert_em(expr, -EASSERT, "Assertion failed")

/*! @brief Check a condition and abort the current function while printing a custom message. */
#ifdef __cplusplus
#define OscAssert_m(expr, m, ...) OscAssert_em(expr, -EASSERT, m, ## __VA_ARGS__)
#else
#define OscAssert_m(expr, m, args ...) OscAssert_em(expr, -EASSERT, m, ## args)
#endif /* __cplusplus */


/* OscCall[_s](): Macros call a function and and abort the current function and execute the exception handler on failure. e is to pass a custom error code. */
/*! @brief Call a function and check it's return code, aborting the current function on an error. */
// FIXME: Too much redundancy between the next four macros.
#ifdef __cplusplus
#define OscCall_s(f, ...) \
	{ \
		_osc_internal_state_.status = f(__VA_ARGS__); \
		if (_osc_internal_state_.status < SUCCESS) \
			OscFail_es(_osc_internal_state_.status); \
	}
#else
#define OscCall_s(f, args ...) \
	{ \
		_osc_internal_state_.status = f(args); \
		if (_osc_internal_state_.status < SUCCESS) \
			OscFail_es(_osc_internal_state_.status); \
	}
#endif /* __cplusplus */


/*! @brief Call a function and check it's return code, aborting the current function with a default message on an error. */

#ifdef __cplusplus
#define OscCall(f, ...) \
	{ \
		_osc_internal_state_.status = f(__VA_ARGS__); \
		if (_osc_internal_state_.status < SUCCESS) \
			OscFail_em(_osc_internal_state_.status, "%s(): Error %d", #f, (int) _osc_internal_state_.status); \
	}

#define OscCall_is(f, ...) \
	{ \
		_osc_internal_state_.status = f(__VA_ARGS__); \
	}

#define OscCall_i(f, ...) \
	{ \
		_osc_internal_state_.status = f(__VA_ARGS__); \
		if (_osc_internal_state_.status < SUCCESS) \
			OscMark_m("%s(): Error %d", #f, (int) _osc_internal_state_.status); \
	}

#else
#define OscCall(f, args ...) \
	{ \
		_osc_internal_state_.status = f(args); \
		if (_osc_internal_state_.status < SUCCESS) \
			OscFail_em(_osc_internal_state_.status, "%s(): Error %d", #f, (int) _osc_internal_state_.status); \
	}

#define OscCall_is(f, args ...) \
	{ \
		_osc_internal_state_.status = f(args); \
	}

#define OscCall_i(f, args ...) \
	{ \
		_osc_internal_state_.status = f(args); \
		if (_osc_internal_state_.status < SUCCESS) \
			OscMark_m("%s(): Error %d", #f, (int) _osc_internal_state_.status); \
	}

#endif /* __cplusplus */




#define OscLastError() _osc_internal_state_.error

#define OscLastStatus() _osc_internal_state_.status

/*! @brief Define general non-module-specific error codes for the OSC framework */
enum EnOscErrors {
	SUCCESS = 0,
	EGENERAL,
	EASSERT,
	EPOOL,
	ELIST,
	EOUT_OF_MEMORY,
	ETIMEOUT,
	EUNABLE_TO_OPEN_FILE,
	EINVALID_PARAMETER,
	EDEVICE,
	ENOTHING_TO_ABORT,
	EDEVICE_BUSY,
	ECANNOT_DELETE,
	EBUFFER_TOO_SMALL,
	EFILE_ERROR,
	ECANNOT_UNLOAD,
	ENR_OF_INSTANCES_EXHAUSTED,
	EFILE_PARSING_ERROR,
	EALREADY_INITIALIZED,
	ENOT_INITIALIZED,
	ENO_SUCH_DEVICE,
	EUNABLE_TO_READ,
	ETRY_AGAIN,
	EINTERRUPTED,
	EUNSUPPORTED
};

/* Define an offset for all modules, which allows it to define module-specific errors that do not overlap. */
/*! @brief Error identifier offset of the cam module. */
#define OSC_CAM_ERROR_OFFSET 100
/*! @brief Error identifier offset of the cpld module. */
#define OSC_CPLD_ERROR_OFFSET 200
/*! @brief Error identifier offset of the lgx module. */
#define OSC_LGX_ERROR_OFFSET 300
/*! @brief Error identifier offset of the log module. */
#define OSC_LOG_ERROR_OFFSET 400
/*! @brief Error identifier offset of the sim module. */
#define OSC_SIM_ERROR_OFFSET 500
/*! @brief Error identifier offset of the bmp module. */
#define OSC_BMP_ERROR_OFFSET 600
/*! @brief Error identifier offset of the swr module. */
#define OSC_SWR_ERROR_OFFSET 700
/*! @brief Error identifier offset of the srd module. */
#define OSC_SRD_ERROR_OFFSET 800
/*! @brief Error identifier offset of the ipc module. */
#define OSC_IPC_ERROR_OFFSET 900
/*! @brief Error identifier offset of the frd module. */
#define OSC_FRD_ERROR_OFFSET 1000
/*! @brief Error identifier offset of the dma module. */
#define OSC_DMA_ERROR_OFFSET 1100
/*! @brief Error identifier offset of the hsm module. */
#define OSC_HSM_ERROR_OFFSET 1200
/*! @brief Error identifier offset of the cfg module. */
#define OSC_CFG_ERROR_OFFSET 1300

#endif /* OSCAR_INCLUDE_ERROR_H_ */
