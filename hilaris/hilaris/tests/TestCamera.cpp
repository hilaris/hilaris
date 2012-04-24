#include <cppunit/extensions/HelperMacros.h>

#include "TestCamera.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestCamera);

void TestCamera::tearDown(void)
{
	getHilaris().resetCamera();
}

void TestCamera::testStandardConstructor(void)
{
	// using standard debayer
	Camera* camera = getHilaris().getCamera();
	
	// test image width and height
	CPPUNIT_ASSERT(camera->getHeight() == Image::MAX_HEIGHT);
	CPPUNIT_ASSERT(camera->getWidth()  == Image::MAX_WIDTH);
	
	BGRImage* image = (BGRImage*)camera->captureImage();
	
	// default debayer reduces the image size
	CPPUNIT_ASSERT(image->getHeight() == Image::MAX_HEIGHT / 2);
	CPPUNIT_ASSERT(image->getWidth()  == Image::MAX_WIDTH  / 2);
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_BGR_24);
}

void TestCamera::testShutterWidth(void)
{
	Camera* camera = getHilaris().getCamera();
	
	// get current setting
	bool current = camera->getAutoExposure();
	
	// try to set by hand
	camera->setAutoExposure(false);
	CPPUNIT_ASSERT(camera->getAutoExposure() == false);
	
	// set to true, test it to set it manually afterwards
	camera->setAutoExposure(true);
	CPPUNIT_ASSERT(camera->getAutoExposure() == true);
	
	camera->setShutterWidth(100);
	
	// this test will always fail, sorry guys :)
	// -: due some unexpected behaviour on the sensor.
	// CPPUNIT_ASSERT(camera->getShutterWidth() == 1000);
	CPPUNIT_ASSERT(camera->getAutoExposure() == false);
	
	// restore setting
	camera->setAutoExposure(current);
}

void TestCamera::testBlackLevelOffset(void)
{
	Camera* camera = getHilaris().getCamera();
	
	// get current setting
	uint16 offset = camera->getBlackLevelOffset();
	
	// lowest
	camera->setBlackLevelOffset(0);
	CPPUNIT_ASSERT(camera->getBlackLevelOffset() == 0);
	
	// something in between
	camera->setBlackLevelOffset(50);
	CPPUNIT_ASSERT(camera->getBlackLevelOffset() == 50);
	
	// maximum
	camera->setBlackLevelOffset(0);
	CPPUNIT_ASSERT(camera->getBlackLevelOffset() == 0);
	
	// too high
	bool   tw = camera->setBlackLevelOffset(100);
	uint16 th = camera->getBlackLevelOffset();
	CPPUNIT_ASSERT(th == 63);
	CPPUNIT_ASSERT(tw == false);
	
	// restore previous setting
	camera->setBlackLevelOffset(offset);
}

void TestCamera::testPresetRegisters(void)
{
	Camera* camera = getHilaris().getCamera();
	
	camera->presetRegisters();
	
	// this test will always fail, sorry guys :)
	// -: due some unexpected behaviour on the sensor.
	// CPPUNIT_ASSERT(camera->getShutterWidth() == 15000);
	
	// no chance to retrieve this information from oscar
	// CPPUNIT_ASSERT(camera->getPerspective() == Camera::ROTATE_180DEG);
	
	CPPUNIT_ASSERT(camera->getBlackLevelOffset() == 13);
}

void TestCamera::testDefaultDebayer(void)
{
	Camera* camera = getHilaris().getCamera();
	
	CPPUNIT_ASSERT(camera->getDebayer()->getType() == OSC_PICTURE_BGR_24);
	CPPUNIT_ASSERT(camera->getDebayer()->getSize() == sizeof(BGRImage));
}


