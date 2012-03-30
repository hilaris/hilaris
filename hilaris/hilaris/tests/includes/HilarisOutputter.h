#ifndef CPPUNIT_HILARISOUTPUTTER_H
#define CPPUNIT_HILARISOUTPUTTER_H

#include <cppunit/Portability.h>
#include <cppunit/Outputter.h>
#include <cppunit/portability/Stream.h>

CPPUNIT_NS_BEGIN

class Exception;
class SourceLine;
class TestResultCollector;
class TestFailure;

class CPPUNIT_API HilarisOutputter : public Outputter
{
	public:
		HilarisOutputter(TestResultCollector *result, OStream &stream);

		virtual ~HilarisOutputter();

		void write();
		virtual void printFailures();
		virtual void printHeader();

		virtual void printFailure( TestFailure *failure,
		int failureNumber );
		virtual void printFailureListMark( int failureNumber );
		virtual void printFailureTestName( TestFailure *failure );
		virtual void printFailureType( TestFailure *failure );
		virtual void printFailureLocation( SourceLine sourceLine );
		virtual void printFailureDetail( Exception *thrownException );
		virtual void printFailureWarning();
		virtual void printStatistics();

	protected:
		TestResultCollector *m_result;
		OStream &m_stream;

	private:
		HilarisOutputter( const HilarisOutputter &copy );
		void operator =( const HilarisOutputter &copy );
};

CPPUNIT_NS_END

#endif
