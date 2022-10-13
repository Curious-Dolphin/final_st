#include"xiApiPlusOcv.hpp"

//-------------------------------------------------------------------------------------------------------------------
// xiAPIplus parameters implementation file - created from gen_xiAPIplus_cpp_file.xslt
// XIMEA Application Programming Interface Object Oriented Approach
//-------------------------------------------------------------------------------------------------------------------


//#include <xiAPIplus/xiapiplus.h>

	//-------------------------------------------------------------------------------------------------------------------
	// xiApi public parameters
	


	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Basic
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Exposure time in microseconds (XI_PRM_EXPOSURE)
	float xiAPIplus_Camera::GetExposureTime()
	{
		float val=0;
		
		CheckCamHandle("GetExposureTime");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_EXPOSURE, &val);
		CheckResult(res,"GetExposureTime");
		return val;
	}

	float xiAPIplus_Camera::GetExposureTime_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetExposureTime" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_EXPOSURE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetExposureTime" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetExposureTime_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetExposureTime" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_EXPOSURE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetExposureTime" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetExposureTime_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetExposureTime" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_EXPOSURE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetExposureTime" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetExposureTime(float ExposureTime)
	{
		
		CheckCamHandle("SetExposureTime");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_EXPOSURE, ExposureTime);
		CheckResult(res,"SetExposureTime");
	}
	 
	
	// Selector for Exposure parameter (XI_PRM_EXPOSURE_TIME_SELECTOR)
	XI_EXPOSURE_TIME_SELECTOR_TYPE xiAPIplus_Camera::GetExposureTimeSelector()
	{
		int val=0;
		
		CheckCamHandle("GetExposureTimeSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_EXPOSURE_TIME_SELECTOR, &val);
		CheckResult(res,"GetExposureTimeSelector");
		return (XI_EXPOSURE_TIME_SELECTOR_TYPE)val;
	}
	
	XI_EXPOSURE_TIME_SELECTOR_TYPE xiAPIplus_Camera::GetExposureTimeSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetExposureTimeSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_EXPOSURE_TIME_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetExposureTimeSelector" "_Maximum");
		return (XI_EXPOSURE_TIME_SELECTOR_TYPE)val;
	}
	
	XI_EXPOSURE_TIME_SELECTOR_TYPE xiAPIplus_Camera::GetExposureTimeSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetExposureTimeSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_EXPOSURE_TIME_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetExposureTimeSelector" "_Minimum");
		return (XI_EXPOSURE_TIME_SELECTOR_TYPE)val;
	}
	
	int xiAPIplus_Camera::GetExposureTimeSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetExposureTimeSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_EXPOSURE_TIME_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetExposureTimeSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetExposureTimeSelector(XI_EXPOSURE_TIME_SELECTOR_TYPE ExposureTimeSelector)
	{
		
		CheckCamHandleInt("SetExposureTimeSelector",(int)ExposureTimeSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_EXPOSURE_TIME_SELECTOR, ExposureTimeSelector);
		CheckResult(res,"SetExposureTimeSelector");
	}
	 
	
	// Sets the number of times of exposure in one frame. (XI_PRM_EXPOSURE_BURST_COUNT)
	// integer type
	int xiAPIplus_Camera::GetExposureBurstCount()
	{
		CheckCamHandle("GetExposureBurstCount");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_EXPOSURE_BURST_COUNT, &val);
		CheckResult(res,"GetExposureBurstCount");
		return val;	
	}
	int xiAPIplus_Camera::GetExposureBurstCount_Maximum()
	{		
		CheckCamHandle("GetExposureBurstCount" "_Maximum");
		int val=0;
		CheckCamHandle("GetExposureBurstCount");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_EXPOSURE_BURST_COUNT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetExposureBurstCount" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetExposureBurstCount_Minimum()
	{
		CheckCamHandle("GetExposureBurstCount" "_Minimum");
		int val=0;
		CheckCamHandle("GetExposureBurstCount");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_EXPOSURE_BURST_COUNT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetExposureBurstCount" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetExposureBurstCount_Increment()
	{
		CheckCamHandle("GetExposureBurstCount" "_Increment");
		int val=0;
		CheckCamHandle("GetExposureBurstCount");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_EXPOSURE_BURST_COUNT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetExposureBurstCount" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetExposureBurstCount(int ExposureBurstCount)
	{
		
		CheckCamHandleInt("SetExposureBurstCount",ExposureBurstCount);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_EXPOSURE_BURST_COUNT, ExposureBurstCount);
		CheckResult(res,"SetExposureBurstCount");
	}
	 
	
	// Gain selector for parameter Gain allows to select different type of gains. (XI_PRM_GAIN_SELECTOR)
	XI_GAIN_SELECTOR_TYPE xiAPIplus_Camera::GetGainSelector()
	{
		int val=0;
		
		CheckCamHandle("GetGainSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GAIN_SELECTOR, &val);
		CheckResult(res,"GetGainSelector");
		return (XI_GAIN_SELECTOR_TYPE)val;
	}
	
	XI_GAIN_SELECTOR_TYPE xiAPIplus_Camera::GetGainSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetGainSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GAIN_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetGainSelector" "_Maximum");
		return (XI_GAIN_SELECTOR_TYPE)val;
	}
	
	XI_GAIN_SELECTOR_TYPE xiAPIplus_Camera::GetGainSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetGainSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GAIN_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetGainSelector" "_Minimum");
		return (XI_GAIN_SELECTOR_TYPE)val;
	}
	
	int xiAPIplus_Camera::GetGainSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetGainSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GAIN_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetGainSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetGainSelector(XI_GAIN_SELECTOR_TYPE GainSelector)
	{
		
		CheckCamHandleInt("SetGainSelector",(int)GainSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_GAIN_SELECTOR, GainSelector);
		CheckResult(res,"SetGainSelector");
	}
	 
	
	// Gain in dB (XI_PRM_GAIN)
	float xiAPIplus_Camera::GetGain()
	{
		float val=0;
		
		CheckCamHandle("GetGain");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_GAIN, &val);
		CheckResult(res,"GetGain");
		return val;
	}

	float xiAPIplus_Camera::GetGain_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetGain" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_GAIN XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetGain" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetGain_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetGain" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_GAIN XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetGain" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetGain_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetGain" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_GAIN XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetGain" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetGain(float Gain)
	{
		
		CheckCamHandle("SetGain");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_GAIN, Gain);
		CheckResult(res,"SetGain");
	}
	 
	
	// Change image resolution by binning or skipping. (XI_PRM_DOWNSAMPLING)
	XI_DOWNSAMPLING_VALUE xiAPIplus_Camera::GetDownsampling()
	{
		int val=0;
		
		CheckCamHandle("GetDownsampling");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DOWNSAMPLING, &val);
		CheckResult(res,"GetDownsampling");
		return (XI_DOWNSAMPLING_VALUE)val;
	}
	
	XI_DOWNSAMPLING_VALUE xiAPIplus_Camera::GetDownsampling_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetDownsampling" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DOWNSAMPLING XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDownsampling" "_Maximum");
		return (XI_DOWNSAMPLING_VALUE)val;
	}
	
	XI_DOWNSAMPLING_VALUE xiAPIplus_Camera::GetDownsampling_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetDownsampling" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DOWNSAMPLING XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDownsampling" "_Minimum");
		return (XI_DOWNSAMPLING_VALUE)val;
	}
	
	int xiAPIplus_Camera::GetDownsampling_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetDownsampling" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DOWNSAMPLING XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDownsampling" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetDownsampling(XI_DOWNSAMPLING_VALUE Downsampling)
	{
		
		CheckCamHandleInt("SetDownsampling",(int)Downsampling);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DOWNSAMPLING, Downsampling);
		CheckResult(res,"SetDownsampling");
	}
	 
	
	// Change image downsampling type. (XI_PRM_DOWNSAMPLING_TYPE)
	XI_DOWNSAMPLING_TYPE xiAPIplus_Camera::GetDownsamplingType()
	{
		int val=0;
		
		CheckCamHandle("GetDownsamplingType");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DOWNSAMPLING_TYPE, &val);
		CheckResult(res,"GetDownsamplingType");
		return (XI_DOWNSAMPLING_TYPE)val;
	}
	
	XI_DOWNSAMPLING_TYPE xiAPIplus_Camera::GetDownsamplingType_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetDownsamplingType" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DOWNSAMPLING_TYPE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDownsamplingType" "_Maximum");
		return (XI_DOWNSAMPLING_TYPE)val;
	}
	
	XI_DOWNSAMPLING_TYPE xiAPIplus_Camera::GetDownsamplingType_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetDownsamplingType" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DOWNSAMPLING_TYPE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDownsamplingType" "_Minimum");
		return (XI_DOWNSAMPLING_TYPE)val;
	}
	
	int xiAPIplus_Camera::GetDownsamplingType_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetDownsamplingType" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DOWNSAMPLING_TYPE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDownsamplingType" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetDownsamplingType(XI_DOWNSAMPLING_TYPE DownsamplingType)
	{
		
		CheckCamHandleInt("SetDownsamplingType",(int)DownsamplingType);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DOWNSAMPLING_TYPE, DownsamplingType);
		CheckResult(res,"SetDownsamplingType");
	}
	 
	
	// Selects which test pattern generator is controlled by the test pattern feature. (XI_PRM_TEST_PATTERN_GENERATOR_SELECTOR)
	XI_TEST_PATTERN_GENERATOR xiAPIplus_Camera::GetTestPatternGeneratorSelector()
	{
		int val=0;
		
		CheckCamHandle("GetTestPatternGeneratorSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEST_PATTERN_GENERATOR_SELECTOR, &val);
		CheckResult(res,"GetTestPatternGeneratorSelector");
		return (XI_TEST_PATTERN_GENERATOR)val;
	}
	
	XI_TEST_PATTERN_GENERATOR xiAPIplus_Camera::GetTestPatternGeneratorSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetTestPatternGeneratorSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEST_PATTERN_GENERATOR_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTestPatternGeneratorSelector" "_Maximum");
		return (XI_TEST_PATTERN_GENERATOR)val;
	}
	
	XI_TEST_PATTERN_GENERATOR xiAPIplus_Camera::GetTestPatternGeneratorSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetTestPatternGeneratorSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEST_PATTERN_GENERATOR_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTestPatternGeneratorSelector" "_Minimum");
		return (XI_TEST_PATTERN_GENERATOR)val;
	}
	
	int xiAPIplus_Camera::GetTestPatternGeneratorSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetTestPatternGeneratorSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEST_PATTERN_GENERATOR_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTestPatternGeneratorSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetTestPatternGeneratorSelector(XI_TEST_PATTERN_GENERATOR TestPatternGeneratorSelector)
	{
		
		CheckCamHandleInt("SetTestPatternGeneratorSelector",(int)TestPatternGeneratorSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_TEST_PATTERN_GENERATOR_SELECTOR, TestPatternGeneratorSelector);
		CheckResult(res,"SetTestPatternGeneratorSelector");
	}
	 
	
	// Selects which test pattern type is generated by the selected generator. (XI_PRM_TEST_PATTERN)
	XI_TEST_PATTERN xiAPIplus_Camera::GetTestPattern()
	{
		int val=0;
		
		CheckCamHandle("GetTestPattern");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEST_PATTERN, &val);
		CheckResult(res,"GetTestPattern");
		return (XI_TEST_PATTERN)val;
	}
	
	XI_TEST_PATTERN xiAPIplus_Camera::GetTestPattern_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetTestPattern" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEST_PATTERN XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTestPattern" "_Maximum");
		return (XI_TEST_PATTERN)val;
	}
	
	XI_TEST_PATTERN xiAPIplus_Camera::GetTestPattern_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetTestPattern" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEST_PATTERN XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTestPattern" "_Minimum");
		return (XI_TEST_PATTERN)val;
	}
	
	int xiAPIplus_Camera::GetTestPattern_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetTestPattern" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEST_PATTERN XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTestPattern" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetTestPattern(XI_TEST_PATTERN TestPattern)
	{
		
		CheckCamHandleInt("SetTestPattern",(int)TestPattern);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_TEST_PATTERN, TestPattern);
		CheckResult(res,"SetTestPattern");
	}
	 
	
	// Output data format. (XI_PRM_IMAGE_DATA_FORMAT)
	XI_IMG_FORMAT xiAPIplus_Camera::GetImageDataFormat()
	{
		int val=0;
		
		CheckCamHandle("GetImageDataFormat");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_DATA_FORMAT, &val);
		CheckResult(res,"GetImageDataFormat");
		return (XI_IMG_FORMAT)val;
	}
	
	XI_IMG_FORMAT xiAPIplus_Camera::GetImageDataFormat_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetImageDataFormat" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_DATA_FORMAT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetImageDataFormat" "_Maximum");
		return (XI_IMG_FORMAT)val;
	}
	
	XI_IMG_FORMAT xiAPIplus_Camera::GetImageDataFormat_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetImageDataFormat" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_DATA_FORMAT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetImageDataFormat" "_Minimum");
		return (XI_IMG_FORMAT)val;
	}
	
	int xiAPIplus_Camera::GetImageDataFormat_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetImageDataFormat" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_DATA_FORMAT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetImageDataFormat" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetImageDataFormat(XI_IMG_FORMAT ImageDataFormat)
	{
		
		CheckCamHandleInt("SetImageDataFormat",(int)ImageDataFormat);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_IMAGE_DATA_FORMAT, ImageDataFormat);
		CheckResult(res,"SetImageDataFormat");
	}
	 
	
	// Change sensor shutter type(CMOS sensor). (XI_PRM_SHUTTER_TYPE)
	XI_SHUTTER_TYPE xiAPIplus_Camera::GetShutterType()
	{
		int val=0;
		
		CheckCamHandle("GetShutterType");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SHUTTER_TYPE, &val);
		CheckResult(res,"GetShutterType");
		return (XI_SHUTTER_TYPE)val;
	}
	
	XI_SHUTTER_TYPE xiAPIplus_Camera::GetShutterType_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetShutterType" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SHUTTER_TYPE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetShutterType" "_Maximum");
		return (XI_SHUTTER_TYPE)val;
	}
	
	XI_SHUTTER_TYPE xiAPIplus_Camera::GetShutterType_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetShutterType" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SHUTTER_TYPE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetShutterType" "_Minimum");
		return (XI_SHUTTER_TYPE)val;
	}
	
	int xiAPIplus_Camera::GetShutterType_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetShutterType" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SHUTTER_TYPE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetShutterType" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetShutterType(XI_SHUTTER_TYPE ShutterType)
	{
		
		CheckCamHandleInt("SetShutterType",(int)ShutterType);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_SHUTTER_TYPE, ShutterType);
		CheckResult(res,"SetShutterType");
	}
	 
	
	// Number of taps (XI_PRM_SENSOR_TAPS)
	XI_SENSOR_TAP_CNT xiAPIplus_Camera::GetSensorTaps()
	{
		int val=0;
		
		CheckCamHandle("GetSensorTaps");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_TAPS, &val);
		CheckResult(res,"GetSensorTaps");
		return (XI_SENSOR_TAP_CNT)val;
	}
	
	XI_SENSOR_TAP_CNT xiAPIplus_Camera::GetSensorTaps_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetSensorTaps" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_TAPS XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetSensorTaps" "_Maximum");
		return (XI_SENSOR_TAP_CNT)val;
	}
	
	XI_SENSOR_TAP_CNT xiAPIplus_Camera::GetSensorTaps_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetSensorTaps" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_TAPS XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetSensorTaps" "_Minimum");
		return (XI_SENSOR_TAP_CNT)val;
	}
	
	int xiAPIplus_Camera::GetSensorTaps_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetSensorTaps" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_TAPS XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetSensorTaps" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetSensorTaps(XI_SENSOR_TAP_CNT SensorTaps)
	{
		
		CheckCamHandleInt("SetSensorTaps",(int)SensorTaps);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_SENSOR_TAPS, SensorTaps);
		CheckResult(res,"SetSensorTaps");
	}
	 
	
	// Automatic exposure/gain (XI_PRM_AEAG)
	bool xiAPIplus_Camera::IsAutoExposureAutoGain()
	{
		int val=0;
		
		CheckCamHandle("IsAutoExposureAutoGain");
		
		xiGetParamInt(camera_handle, XI_PRM_AEAG, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableAutoExposureAutoGain()
	{
		
		CheckCamHandle("IsAutoExposureAutoGain");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_AEAG, XI_ON);
		CheckResult(res,"EnableAutoExposureAutoGain");
	}

	void xiAPIplus_Camera::DisableAutoExposureAutoGain()
	{
		
		CheckCamHandle("DisableAutoExposureAutoGain");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_AEAG, XI_OFF);
		CheckResult(res,"DisableAutoExposureAutoGain");
	}	
	 
	
	// Automatic exposure/gain ROI offset X (XI_PRM_AEAG_ROI_OFFSET_X)
	// integer type
	int xiAPIplus_Camera::GetAutoExposureAutoGainROIoffsetX()
	{
		CheckCamHandle("GetAutoExposureAutoGainROIoffsetX");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_OFFSET_X, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIoffsetX");
		return val;	
	}
	int xiAPIplus_Camera::GetAutoExposureAutoGainROIoffsetX_Maximum()
	{		
		CheckCamHandle("GetAutoExposureAutoGainROIoffsetX" "_Maximum");
		int val=0;
		CheckCamHandle("GetAutoExposureAutoGainROIoffsetX");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_OFFSET_X XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIoffsetX" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetAutoExposureAutoGainROIoffsetX_Minimum()
	{
		CheckCamHandle("GetAutoExposureAutoGainROIoffsetX" "_Minimum");
		int val=0;
		CheckCamHandle("GetAutoExposureAutoGainROIoffsetX");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_OFFSET_X XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIoffsetX" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetAutoExposureAutoGainROIoffsetX_Increment()
	{
		CheckCamHandle("GetAutoExposureAutoGainROIoffsetX" "_Increment");
		int val=0;
		CheckCamHandle("GetAutoExposureAutoGainROIoffsetX");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_OFFSET_X XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIoffsetX" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetAutoExposureAutoGainROIoffsetX(int AutoExposureAutoGainROIoffsetX)
	{
		
		CheckCamHandleInt("SetAutoExposureAutoGainROIoffsetX",AutoExposureAutoGainROIoffsetX);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_AEAG_ROI_OFFSET_X, AutoExposureAutoGainROIoffsetX);
		CheckResult(res,"SetAutoExposureAutoGainROIoffsetX");
	}
	 
	
	// Automatic exposure/gain ROI offset Y (XI_PRM_AEAG_ROI_OFFSET_Y)
	// integer type
	int xiAPIplus_Camera::GetAutoExposureAutoGainROIoffsetY()
	{
		CheckCamHandle("GetAutoExposureAutoGainROIoffsetY");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_OFFSET_Y, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIoffsetY");
		return val;	
	}
	int xiAPIplus_Camera::GetAutoExposureAutoGainROIoffsetY_Maximum()
	{		
		CheckCamHandle("GetAutoExposureAutoGainROIoffsetY" "_Maximum");
		int val=0;
		CheckCamHandle("GetAutoExposureAutoGainROIoffsetY");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_OFFSET_Y XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIoffsetY" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetAutoExposureAutoGainROIoffsetY_Minimum()
	{
		CheckCamHandle("GetAutoExposureAutoGainROIoffsetY" "_Minimum");
		int val=0;
		CheckCamHandle("GetAutoExposureAutoGainROIoffsetY");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_OFFSET_Y XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIoffsetY" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetAutoExposureAutoGainROIoffsetY_Increment()
	{
		CheckCamHandle("GetAutoExposureAutoGainROIoffsetY" "_Increment");
		int val=0;
		CheckCamHandle("GetAutoExposureAutoGainROIoffsetY");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_OFFSET_Y XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIoffsetY" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetAutoExposureAutoGainROIoffsetY(int AutoExposureAutoGainROIoffsetY)
	{
		
		CheckCamHandleInt("SetAutoExposureAutoGainROIoffsetY",AutoExposureAutoGainROIoffsetY);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_AEAG_ROI_OFFSET_Y, AutoExposureAutoGainROIoffsetY);
		CheckResult(res,"SetAutoExposureAutoGainROIoffsetY");
	}
	 
	
	// Automatic exposure/gain ROI Width (XI_PRM_AEAG_ROI_WIDTH)
	// integer type
	int xiAPIplus_Camera::GetAutoExposureAutoGainROIWidth()
	{
		CheckCamHandle("GetAutoExposureAutoGainROIWidth");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_WIDTH, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIWidth");
		return val;	
	}
	int xiAPIplus_Camera::GetAutoExposureAutoGainROIWidth_Maximum()
	{		
		CheckCamHandle("GetAutoExposureAutoGainROIWidth" "_Maximum");
		int val=0;
		CheckCamHandle("GetAutoExposureAutoGainROIWidth");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_WIDTH XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIWidth" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetAutoExposureAutoGainROIWidth_Minimum()
	{
		CheckCamHandle("GetAutoExposureAutoGainROIWidth" "_Minimum");
		int val=0;
		CheckCamHandle("GetAutoExposureAutoGainROIWidth");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_WIDTH XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIWidth" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetAutoExposureAutoGainROIWidth_Increment()
	{
		CheckCamHandle("GetAutoExposureAutoGainROIWidth" "_Increment");
		int val=0;
		CheckCamHandle("GetAutoExposureAutoGainROIWidth");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_WIDTH XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIWidth" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetAutoExposureAutoGainROIWidth(int AutoExposureAutoGainROIWidth)
	{
		
		CheckCamHandleInt("SetAutoExposureAutoGainROIWidth",AutoExposureAutoGainROIWidth);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_AEAG_ROI_WIDTH, AutoExposureAutoGainROIWidth);
		CheckResult(res,"SetAutoExposureAutoGainROIWidth");
	}
	 
	
	// Automatic exposure/gain ROI Height (XI_PRM_AEAG_ROI_HEIGHT)
	// integer type
	int xiAPIplus_Camera::GetAutoExposureAutoGainROIHeight()
	{
		CheckCamHandle("GetAutoExposureAutoGainROIHeight");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_HEIGHT, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIHeight");
		return val;	
	}
	int xiAPIplus_Camera::GetAutoExposureAutoGainROIHeight_Maximum()
	{		
		CheckCamHandle("GetAutoExposureAutoGainROIHeight" "_Maximum");
		int val=0;
		CheckCamHandle("GetAutoExposureAutoGainROIHeight");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_HEIGHT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIHeight" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetAutoExposureAutoGainROIHeight_Minimum()
	{
		CheckCamHandle("GetAutoExposureAutoGainROIHeight" "_Minimum");
		int val=0;
		CheckCamHandle("GetAutoExposureAutoGainROIHeight");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_HEIGHT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIHeight" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetAutoExposureAutoGainROIHeight_Increment()
	{
		CheckCamHandle("GetAutoExposureAutoGainROIHeight" "_Increment");
		int val=0;
		CheckCamHandle("GetAutoExposureAutoGainROIHeight");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_ROI_HEIGHT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAutoExposureAutoGainROIHeight" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetAutoExposureAutoGainROIHeight(int AutoExposureAutoGainROIHeight)
	{
		
		CheckCamHandleInt("SetAutoExposureAutoGainROIHeight",AutoExposureAutoGainROIHeight);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_AEAG_ROI_HEIGHT, AutoExposureAutoGainROIHeight);
		CheckResult(res,"SetAutoExposureAutoGainROIHeight");
	}
	 
	
	// Selector of list used by Sensor Defects Correction parameter (XI_PRM_SENS_DEFECTS_CORR_LIST_SELECTOR)
	XI_SENS_DEFFECTS_CORR_LIST_SELECTOR xiAPIplus_Camera::GetSensorDefectsCorrectionListSelector()
	{
		int val=0;
		
		CheckCamHandle("GetSensorDefectsCorrectionListSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENS_DEFECTS_CORR_LIST_SELECTOR, &val);
		CheckResult(res,"GetSensorDefectsCorrectionListSelector");
		return (XI_SENS_DEFFECTS_CORR_LIST_SELECTOR)val;
	}
	
	XI_SENS_DEFFECTS_CORR_LIST_SELECTOR xiAPIplus_Camera::GetSensorDefectsCorrectionListSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetSensorDefectsCorrectionListSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENS_DEFECTS_CORR_LIST_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetSensorDefectsCorrectionListSelector" "_Maximum");
		return (XI_SENS_DEFFECTS_CORR_LIST_SELECTOR)val;
	}
	
	XI_SENS_DEFFECTS_CORR_LIST_SELECTOR xiAPIplus_Camera::GetSensorDefectsCorrectionListSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetSensorDefectsCorrectionListSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENS_DEFECTS_CORR_LIST_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetSensorDefectsCorrectionListSelector" "_Minimum");
		return (XI_SENS_DEFFECTS_CORR_LIST_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetSensorDefectsCorrectionListSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetSensorDefectsCorrectionListSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENS_DEFECTS_CORR_LIST_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetSensorDefectsCorrectionListSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetSensorDefectsCorrectionListSelector(XI_SENS_DEFFECTS_CORR_LIST_SELECTOR SensorDefectsCorrectionListSelector)
	{
		
		CheckCamHandleInt("SetSensorDefectsCorrectionListSelector",(int)SensorDefectsCorrectionListSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_SENS_DEFECTS_CORR_LIST_SELECTOR, SensorDefectsCorrectionListSelector);
		CheckResult(res,"SetSensorDefectsCorrectionListSelector");
	}
	 
	
	// Sets/Gets sensor defects list in special text format (XI_PRM_SENS_DEFECTS_CORR_LIST_CONTENT)
	void xiAPIplus_Camera::GetSensDefectsCorrListContent(char* buffer, int buffer_length)
	{
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_SENS_DEFECTS_CORR_LIST_CONTENT, buffer, buffer_length);
		CheckResult(res,"GetSensDefectsCorrListContent");
	}
	
	void xiAPIplus_Camera::SetSensDefectsCorrListContent(char* new_value)
	{
		
		XI_RETURN res=xiSetParamString(camera_handle, XI_PRM_SENS_DEFECTS_CORR_LIST_CONTENT, new_value, (DWORD)strlen(new_value));
		CheckResult(res,"SetSensDefectsCorrListContent");
	}
	 
	
	// Correction of sensor defects (pixels, columns, rows) enable/disable (XI_PRM_SENS_DEFECTS_CORR)
	bool xiAPIplus_Camera::IsSensorDefectsCorrection()
	{
		int val=0;
		
		CheckCamHandle("IsSensorDefectsCorrection");
		
		xiGetParamInt(camera_handle, XI_PRM_SENS_DEFECTS_CORR, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableSensorDefectsCorrection()
	{
		
		CheckCamHandle("IsSensorDefectsCorrection");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_SENS_DEFECTS_CORR, XI_ON);
		CheckResult(res,"EnableSensorDefectsCorrection");
	}

	void xiAPIplus_Camera::DisableSensorDefectsCorrection()
	{
		
		CheckCamHandle("DisableSensorDefectsCorrection");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_SENS_DEFECTS_CORR, XI_OFF);
		CheckResult(res,"DisableSensorDefectsCorrection");
	}	
	 
	
	// Automatic white balance (XI_PRM_AUTO_WB)
	bool xiAPIplus_Camera::IsWhiteBalanceAuto()
	{
		int val=0;
		
		CheckCamHandle("IsWhiteBalanceAuto");
		
		xiGetParamInt(camera_handle, XI_PRM_AUTO_WB, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableWhiteBalanceAuto()
	{
		
		CheckCamHandle("IsWhiteBalanceAuto");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_AUTO_WB, XI_ON);
		CheckResult(res,"EnableWhiteBalanceAuto");
	}

	void xiAPIplus_Camera::DisableWhiteBalanceAuto()
	{
		
		CheckCamHandle("DisableWhiteBalanceAuto");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_AUTO_WB, XI_OFF);
		CheckResult(res,"DisableWhiteBalanceAuto");
	}	
	 
	
	// Calculates White Balance(xiGetImage function must be called) (XI_PRM_MANUAL_WB)
	void xiAPIplus_Camera::SetWhiteBalanceManualNow(int WhiteBalanceManualNow)
	{
		
		CheckCamHandleInt("SetWhiteBalanceManualNow",WhiteBalanceManualNow);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_MANUAL_WB, WhiteBalanceManualNow);
		CheckResult(res,"SetWhiteBalanceManualNow");
	}
	 
	
	// White balance offset X (XI_PRM_WB_ROI_OFFSET_X)
	// integer type
	int xiAPIplus_Camera::GetWhiteBalanceROIoffsetX()
	{
		CheckCamHandle("GetWhiteBalanceROIoffsetX");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_OFFSET_X, &val);
		CheckResult(res,"GetWhiteBalanceROIoffsetX");
		return val;	
	}
	int xiAPIplus_Camera::GetWhiteBalanceROIoffsetX_Maximum()
	{		
		CheckCamHandle("GetWhiteBalanceROIoffsetX" "_Maximum");
		int val=0;
		CheckCamHandle("GetWhiteBalanceROIoffsetX");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_OFFSET_X XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetWhiteBalanceROIoffsetX" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetWhiteBalanceROIoffsetX_Minimum()
	{
		CheckCamHandle("GetWhiteBalanceROIoffsetX" "_Minimum");
		int val=0;
		CheckCamHandle("GetWhiteBalanceROIoffsetX");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_OFFSET_X XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetWhiteBalanceROIoffsetX" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetWhiteBalanceROIoffsetX_Increment()
	{
		CheckCamHandle("GetWhiteBalanceROIoffsetX" "_Increment");
		int val=0;
		CheckCamHandle("GetWhiteBalanceROIoffsetX");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_OFFSET_X XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetWhiteBalanceROIoffsetX" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetWhiteBalanceROIoffsetX(int WhiteBalanceROIoffsetX)
	{
		
		CheckCamHandleInt("SetWhiteBalanceROIoffsetX",WhiteBalanceROIoffsetX);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_WB_ROI_OFFSET_X, WhiteBalanceROIoffsetX);
		CheckResult(res,"SetWhiteBalanceROIoffsetX");
	}
	 
	
	// White balance offset Y (XI_PRM_WB_ROI_OFFSET_Y)
	// integer type
	int xiAPIplus_Camera::GetWhiteBalanceROIoffsetY()
	{
		CheckCamHandle("GetWhiteBalanceROIoffsetY");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_OFFSET_Y, &val);
		CheckResult(res,"GetWhiteBalanceROIoffsetY");
		return val;	
	}
	int xiAPIplus_Camera::GetWhiteBalanceROIoffsetY_Maximum()
	{		
		CheckCamHandle("GetWhiteBalanceROIoffsetY" "_Maximum");
		int val=0;
		CheckCamHandle("GetWhiteBalanceROIoffsetY");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_OFFSET_Y XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetWhiteBalanceROIoffsetY" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetWhiteBalanceROIoffsetY_Minimum()
	{
		CheckCamHandle("GetWhiteBalanceROIoffsetY" "_Minimum");
		int val=0;
		CheckCamHandle("GetWhiteBalanceROIoffsetY");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_OFFSET_Y XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetWhiteBalanceROIoffsetY" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetWhiteBalanceROIoffsetY_Increment()
	{
		CheckCamHandle("GetWhiteBalanceROIoffsetY" "_Increment");
		int val=0;
		CheckCamHandle("GetWhiteBalanceROIoffsetY");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_OFFSET_Y XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetWhiteBalanceROIoffsetY" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetWhiteBalanceROIoffsetY(int WhiteBalanceROIoffsetY)
	{
		
		CheckCamHandleInt("SetWhiteBalanceROIoffsetY",WhiteBalanceROIoffsetY);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_WB_ROI_OFFSET_Y, WhiteBalanceROIoffsetY);
		CheckResult(res,"SetWhiteBalanceROIoffsetY");
	}
	 
	
	// White balance width (XI_PRM_WB_ROI_WIDTH)
	// integer type
	int xiAPIplus_Camera::GetWhiteBalanceROIWidth()
	{
		CheckCamHandle("GetWhiteBalanceROIWidth");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_WIDTH, &val);
		CheckResult(res,"GetWhiteBalanceROIWidth");
		return val;	
	}
	int xiAPIplus_Camera::GetWhiteBalanceROIWidth_Maximum()
	{		
		CheckCamHandle("GetWhiteBalanceROIWidth" "_Maximum");
		int val=0;
		CheckCamHandle("GetWhiteBalanceROIWidth");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_WIDTH XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetWhiteBalanceROIWidth" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetWhiteBalanceROIWidth_Minimum()
	{
		CheckCamHandle("GetWhiteBalanceROIWidth" "_Minimum");
		int val=0;
		CheckCamHandle("GetWhiteBalanceROIWidth");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_WIDTH XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetWhiteBalanceROIWidth" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetWhiteBalanceROIWidth_Increment()
	{
		CheckCamHandle("GetWhiteBalanceROIWidth" "_Increment");
		int val=0;
		CheckCamHandle("GetWhiteBalanceROIWidth");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_WIDTH XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetWhiteBalanceROIWidth" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetWhiteBalanceROIWidth(int WhiteBalanceROIWidth)
	{
		
		CheckCamHandleInt("SetWhiteBalanceROIWidth",WhiteBalanceROIWidth);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_WB_ROI_WIDTH, WhiteBalanceROIWidth);
		CheckResult(res,"SetWhiteBalanceROIWidth");
	}
	 
	
	// White balance height (XI_PRM_WB_ROI_HEIGHT)
	// integer type
	int xiAPIplus_Camera::GetWhiteBalanceROIHeight()
	{
		CheckCamHandle("GetWhiteBalanceROIHeight");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_HEIGHT, &val);
		CheckResult(res,"GetWhiteBalanceROIHeight");
		return val;	
	}
	int xiAPIplus_Camera::GetWhiteBalanceROIHeight_Maximum()
	{		
		CheckCamHandle("GetWhiteBalanceROIHeight" "_Maximum");
		int val=0;
		CheckCamHandle("GetWhiteBalanceROIHeight");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_HEIGHT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetWhiteBalanceROIHeight" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetWhiteBalanceROIHeight_Minimum()
	{
		CheckCamHandle("GetWhiteBalanceROIHeight" "_Minimum");
		int val=0;
		CheckCamHandle("GetWhiteBalanceROIHeight");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_HEIGHT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetWhiteBalanceROIHeight" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetWhiteBalanceROIHeight_Increment()
	{
		CheckCamHandle("GetWhiteBalanceROIHeight" "_Increment");
		int val=0;
		CheckCamHandle("GetWhiteBalanceROIHeight");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WB_ROI_HEIGHT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetWhiteBalanceROIHeight" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetWhiteBalanceROIHeight(int WhiteBalanceROIHeight)
	{
		
		CheckCamHandleInt("SetWhiteBalanceROIHeight",WhiteBalanceROIHeight);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_WB_ROI_HEIGHT, WhiteBalanceROIHeight);
		CheckResult(res,"SetWhiteBalanceROIHeight");
	}
	 
	
	// White balance red coefficient (XI_PRM_WB_KR)
	float xiAPIplus_Camera::GetWhiteBalanceRed()
	{
		float val=0;
		
		CheckCamHandle("GetWhiteBalanceRed");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_WB_KR, &val);
		CheckResult(res,"GetWhiteBalanceRed");
		return val;
	}

	float xiAPIplus_Camera::GetWhiteBalanceRed_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetWhiteBalanceRed" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_WB_KR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetWhiteBalanceRed" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetWhiteBalanceRed_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetWhiteBalanceRed" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_WB_KR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetWhiteBalanceRed" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetWhiteBalanceRed_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetWhiteBalanceRed" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_WB_KR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetWhiteBalanceRed" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetWhiteBalanceRed(float WhiteBalanceRed)
	{
		
		CheckCamHandle("SetWhiteBalanceRed");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_WB_KR, WhiteBalanceRed);
		CheckResult(res,"SetWhiteBalanceRed");
	}
	 
	
	// White balance green coefficient (XI_PRM_WB_KG)
	float xiAPIplus_Camera::GetWhiteBalanceGreen()
	{
		float val=0;
		
		CheckCamHandle("GetWhiteBalanceGreen");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_WB_KG, &val);
		CheckResult(res,"GetWhiteBalanceGreen");
		return val;
	}

	float xiAPIplus_Camera::GetWhiteBalanceGreen_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetWhiteBalanceGreen" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_WB_KG XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetWhiteBalanceGreen" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetWhiteBalanceGreen_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetWhiteBalanceGreen" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_WB_KG XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetWhiteBalanceGreen" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetWhiteBalanceGreen_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetWhiteBalanceGreen" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_WB_KG XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetWhiteBalanceGreen" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetWhiteBalanceGreen(float WhiteBalanceGreen)
	{
		
		CheckCamHandle("SetWhiteBalanceGreen");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_WB_KG, WhiteBalanceGreen);
		CheckResult(res,"SetWhiteBalanceGreen");
	}
	 
	
	// White balance blue coefficient (XI_PRM_WB_KB)
	float xiAPIplus_Camera::GetWhiteBalanceBlue()
	{
		float val=0;
		
		CheckCamHandle("GetWhiteBalanceBlue");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_WB_KB, &val);
		CheckResult(res,"GetWhiteBalanceBlue");
		return val;
	}

	float xiAPIplus_Camera::GetWhiteBalanceBlue_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetWhiteBalanceBlue" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_WB_KB XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetWhiteBalanceBlue" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetWhiteBalanceBlue_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetWhiteBalanceBlue" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_WB_KB XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetWhiteBalanceBlue" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetWhiteBalanceBlue_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetWhiteBalanceBlue" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_WB_KB XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetWhiteBalanceBlue" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetWhiteBalanceBlue(float WhiteBalanceBlue)
	{
		
		CheckCamHandle("SetWhiteBalanceBlue");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_WB_KB, WhiteBalanceBlue);
		CheckResult(res,"SetWhiteBalanceBlue");
	}
	 
	
	// Width of the Image provided by the device (in pixels). (XI_PRM_WIDTH)
	// integer type
	int xiAPIplus_Camera::GetWidth()
	{
		CheckCamHandle("GetWidth");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WIDTH, &val);
		CheckResult(res,"GetWidth");
		return val;	
	}
	int xiAPIplus_Camera::GetWidth_Maximum()
	{		
		CheckCamHandle("GetWidth" "_Maximum");
		int val=0;
		CheckCamHandle("GetWidth");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WIDTH XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetWidth" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetWidth_Minimum()
	{
		CheckCamHandle("GetWidth" "_Minimum");
		int val=0;
		CheckCamHandle("GetWidth");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WIDTH XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetWidth" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetWidth_Increment()
	{
		CheckCamHandle("GetWidth" "_Increment");
		int val=0;
		CheckCamHandle("GetWidth");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_WIDTH XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetWidth" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetWidth(int Width)
	{
		
		CheckCamHandleInt("SetWidth",Width);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_WIDTH, Width);
		CheckResult(res,"SetWidth");
	}
	 
	
	// Height of the Image provided by the device (in pixels). (XI_PRM_HEIGHT)
	// integer type
	int xiAPIplus_Camera::GetHeight()
	{
		CheckCamHandle("GetHeight");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HEIGHT, &val);
		CheckResult(res,"GetHeight");
		return val;	
	}
	int xiAPIplus_Camera::GetHeight_Maximum()
	{		
		CheckCamHandle("GetHeight" "_Maximum");
		int val=0;
		CheckCamHandle("GetHeight");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HEIGHT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetHeight" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetHeight_Minimum()
	{
		CheckCamHandle("GetHeight" "_Minimum");
		int val=0;
		CheckCamHandle("GetHeight");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HEIGHT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetHeight" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetHeight_Increment()
	{
		CheckCamHandle("GetHeight" "_Increment");
		int val=0;
		CheckCamHandle("GetHeight");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HEIGHT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetHeight" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetHeight(int Height)
	{
		
		CheckCamHandleInt("SetHeight",Height);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_HEIGHT, Height);
		CheckResult(res,"SetHeight");
	}
	 
	
	// Horizontal offset from the origin to the area of interest (in pixels). (XI_PRM_OFFSET_X)
	// integer type
	int xiAPIplus_Camera::GetOffsetX()
	{
		CheckCamHandle("GetOffsetX");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OFFSET_X, &val);
		CheckResult(res,"GetOffsetX");
		return val;	
	}
	int xiAPIplus_Camera::GetOffsetX_Maximum()
	{		
		CheckCamHandle("GetOffsetX" "_Maximum");
		int val=0;
		CheckCamHandle("GetOffsetX");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OFFSET_X XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetOffsetX" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetOffsetX_Minimum()
	{
		CheckCamHandle("GetOffsetX" "_Minimum");
		int val=0;
		CheckCamHandle("GetOffsetX");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OFFSET_X XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetOffsetX" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetOffsetX_Increment()
	{
		CheckCamHandle("GetOffsetX" "_Increment");
		int val=0;
		CheckCamHandle("GetOffsetX");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OFFSET_X XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetOffsetX" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetOffsetX(int OffsetX)
	{
		
		CheckCamHandleInt("SetOffsetX",OffsetX);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_OFFSET_X, OffsetX);
		CheckResult(res,"SetOffsetX");
	}
	 
	
	// Vertical offset from the origin to the area of interest (in pixels). (XI_PRM_OFFSET_Y)
	// integer type
	int xiAPIplus_Camera::GetOffsetY()
	{
		CheckCamHandle("GetOffsetY");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OFFSET_Y, &val);
		CheckResult(res,"GetOffsetY");
		return val;	
	}
	int xiAPIplus_Camera::GetOffsetY_Maximum()
	{		
		CheckCamHandle("GetOffsetY" "_Maximum");
		int val=0;
		CheckCamHandle("GetOffsetY");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OFFSET_Y XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetOffsetY" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetOffsetY_Minimum()
	{
		CheckCamHandle("GetOffsetY" "_Minimum");
		int val=0;
		CheckCamHandle("GetOffsetY");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OFFSET_Y XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetOffsetY" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetOffsetY_Increment()
	{
		CheckCamHandle("GetOffsetY" "_Increment");
		int val=0;
		CheckCamHandle("GetOffsetY");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OFFSET_Y XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetOffsetY" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetOffsetY(int OffsetY)
	{
		
		CheckCamHandleInt("SetOffsetY",OffsetY);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_OFFSET_Y, OffsetY);
		CheckResult(res,"SetOffsetY");
	}
	 
	
	// Selects Region in Multiple ROI which parameters are set by width, height, ... ,region mode (XI_PRM_REGION_SELECTOR)
	// integer type
	int xiAPIplus_Camera::GetRegion_selector()
	{
		CheckCamHandle("GetRegion_selector");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_REGION_SELECTOR, &val);
		CheckResult(res,"GetRegion_selector");
		return val;	
	}
	int xiAPIplus_Camera::GetRegion_selector_Maximum()
	{		
		CheckCamHandle("GetRegion_selector" "_Maximum");
		int val=0;
		CheckCamHandle("GetRegion_selector");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_REGION_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetRegion_selector" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetRegion_selector_Minimum()
	{
		CheckCamHandle("GetRegion_selector" "_Minimum");
		int val=0;
		CheckCamHandle("GetRegion_selector");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_REGION_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetRegion_selector" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetRegion_selector_Increment()
	{
		CheckCamHandle("GetRegion_selector" "_Increment");
		int val=0;
		CheckCamHandle("GetRegion_selector");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_REGION_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetRegion_selector" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetRegion_selector(int Region_selector)
	{
		
		CheckCamHandleInt("SetRegion_selector",Region_selector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_REGION_SELECTOR, Region_selector);
		CheckResult(res,"SetRegion_selector");
	}
	 
	
	// Activates/deactivates Region selected by Region Selector (XI_PRM_REGION_MODE)
	// integer type
	int xiAPIplus_Camera::GetRegion_mode()
	{
		CheckCamHandle("GetRegion_mode");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_REGION_MODE, &val);
		CheckResult(res,"GetRegion_mode");
		return val;	
	}
	int xiAPIplus_Camera::GetRegion_mode_Maximum()
	{		
		CheckCamHandle("GetRegion_mode" "_Maximum");
		int val=0;
		CheckCamHandle("GetRegion_mode");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_REGION_MODE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetRegion_mode" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetRegion_mode_Minimum()
	{
		CheckCamHandle("GetRegion_mode" "_Minimum");
		int val=0;
		CheckCamHandle("GetRegion_mode");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_REGION_MODE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetRegion_mode" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetRegion_mode_Increment()
	{
		CheckCamHandle("GetRegion_mode" "_Increment");
		int val=0;
		CheckCamHandle("GetRegion_mode");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_REGION_MODE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetRegion_mode" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetRegion_mode(int Region_mode)
	{
		
		CheckCamHandleInt("SetRegion_mode",Region_mode);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_REGION_MODE, Region_mode);
		CheckResult(res,"SetRegion_mode");
	}
	 
	
	// Horizontal flip enable (XI_PRM_HORIZONTAL_FLIP)
	bool xiAPIplus_Camera::IsHorizontalFlip()
	{
		int val=0;
		
		CheckCamHandle("IsHorizontalFlip");
		
		xiGetParamInt(camera_handle, XI_PRM_HORIZONTAL_FLIP, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableHorizontalFlip()
	{
		
		CheckCamHandle("IsHorizontalFlip");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_HORIZONTAL_FLIP, XI_ON);
		CheckResult(res,"EnableHorizontalFlip");
	}

	void xiAPIplus_Camera::DisableHorizontalFlip()
	{
		
		CheckCamHandle("DisableHorizontalFlip");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_HORIZONTAL_FLIP, XI_OFF);
		CheckResult(res,"DisableHorizontalFlip");
	}	
	 
	
	// Vertical flip enable (XI_PRM_VERTICAL_FLIP)
	bool xiAPIplus_Camera::IsVerticalFlip()
	{
		int val=0;
		
		CheckCamHandle("IsVerticalFlip");
		
		xiGetParamInt(camera_handle, XI_PRM_VERTICAL_FLIP, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableVerticalFlip()
	{
		
		CheckCamHandle("IsVerticalFlip");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_VERTICAL_FLIP, XI_ON);
		CheckResult(res,"EnableVerticalFlip");
	}

	void xiAPIplus_Camera::DisableVerticalFlip()
	{
		
		CheckCamHandle("DisableVerticalFlip");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_VERTICAL_FLIP, XI_OFF);
		CheckResult(res,"DisableVerticalFlip");
	}	
	 
	
	// Selector for Exposure parameter (XI_PRM_INTERLINE_EXPOSURE_MODE)
	XI_INTERLINE_EXPOSURE_MODE_TYPE xiAPIplus_Camera::GetInterlineExposureMode()
	{
		int val=0;
		
		CheckCamHandle("GetInterlineExposureMode");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_INTERLINE_EXPOSURE_MODE, &val);
		CheckResult(res,"GetInterlineExposureMode");
		return (XI_INTERLINE_EXPOSURE_MODE_TYPE)val;
	}
	
	XI_INTERLINE_EXPOSURE_MODE_TYPE xiAPIplus_Camera::GetInterlineExposureMode_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetInterlineExposureMode" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_INTERLINE_EXPOSURE_MODE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetInterlineExposureMode" "_Maximum");
		return (XI_INTERLINE_EXPOSURE_MODE_TYPE)val;
	}
	
	XI_INTERLINE_EXPOSURE_MODE_TYPE xiAPIplus_Camera::GetInterlineExposureMode_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetInterlineExposureMode" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_INTERLINE_EXPOSURE_MODE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetInterlineExposureMode" "_Minimum");
		return (XI_INTERLINE_EXPOSURE_MODE_TYPE)val;
	}
	
	int xiAPIplus_Camera::GetInterlineExposureMode_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetInterlineExposureMode" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_INTERLINE_EXPOSURE_MODE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetInterlineExposureMode" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetInterlineExposureMode(XI_INTERLINE_EXPOSURE_MODE_TYPE InterlineExposureMode)
	{
		
		CheckCamHandleInt("SetInterlineExposureMode",(int)InterlineExposureMode);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_INTERLINE_EXPOSURE_MODE, InterlineExposureMode);
		CheckResult(res,"SetInterlineExposureMode");
	}
	 
	
	// Image flat field correction (XI_PRM_FFC)
	bool xiAPIplus_Camera::IsFlatFieldCorrection()
	{
		int val=0;
		
		CheckCamHandle("IsFlatFieldCorrection");
		
		xiGetParamInt(camera_handle, XI_PRM_FFC, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableFlatFieldCorrection()
	{
		
		CheckCamHandle("IsFlatFieldCorrection");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_FFC, XI_ON);
		CheckResult(res,"EnableFlatFieldCorrection");
	}

	void xiAPIplus_Camera::DisableFlatFieldCorrection()
	{
		
		CheckCamHandle("DisableFlatFieldCorrection");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_FFC, XI_OFF);
		CheckResult(res,"DisableFlatFieldCorrection");
	}	
	 
	
	// Set name of file to be applied for FFC processor. (XI_PRM_FFC_FLAT_FIELD_FILE_NAME)
	void xiAPIplus_Camera::GetFFCFlatFieldFileName(char* buffer, int buffer_length)
	{
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_FFC_FLAT_FIELD_FILE_NAME, buffer, buffer_length);
		CheckResult(res,"GetFFCFlatFieldFileName");
	}
	
	void xiAPIplus_Camera::SetFFCFlatFieldFileName(char* new_value)
	{
		
		XI_RETURN res=xiSetParamString(camera_handle, XI_PRM_FFC_FLAT_FIELD_FILE_NAME, new_value, (DWORD)strlen(new_value));
		CheckResult(res,"SetFFCFlatFieldFileName");
	}
	 
	
	// Set name of file to be applied for FFC processor. (XI_PRM_FFC_DARK_FIELD_FILE_NAME)
	void xiAPIplus_Camera::GetFFCDarkFieldFileName(char* buffer, int buffer_length)
	{
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_FFC_DARK_FIELD_FILE_NAME, buffer, buffer_length);
		CheckResult(res,"GetFFCDarkFieldFileName");
	}
	
	void xiAPIplus_Camera::SetFFCDarkFieldFileName(char* new_value)
	{
		
		XI_RETURN res=xiSetParamString(camera_handle, XI_PRM_FFC_DARK_FIELD_FILE_NAME, new_value, (DWORD)strlen(new_value));
		CheckResult(res,"SetFFCDarkFieldFileName");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Image Format
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Binning engine selector. (XI_PRM_BINNING_SELECTOR)
	XI_BIN_SELECTOR xiAPIplus_Camera::GetBinningSelector()
	{
		int val=0;
		
		CheckCamHandle("GetBinningSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_SELECTOR, &val);
		CheckResult(res,"GetBinningSelector");
		return (XI_BIN_SELECTOR)val;
	}
	
	XI_BIN_SELECTOR xiAPIplus_Camera::GetBinningSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetBinningSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetBinningSelector" "_Maximum");
		return (XI_BIN_SELECTOR)val;
	}
	
	XI_BIN_SELECTOR xiAPIplus_Camera::GetBinningSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetBinningSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetBinningSelector" "_Minimum");
		return (XI_BIN_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetBinningSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetBinningSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetBinningSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetBinningSelector(XI_BIN_SELECTOR BinningSelector)
	{
		
		CheckCamHandleInt("SetBinningSelector",(int)BinningSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_BINNING_SELECTOR, BinningSelector);
		CheckResult(res,"SetBinningSelector");
	}
	 
	
	// Sets the mode to use to combine vertical pixel together. (XI_PRM_BINNING_VERTICAL_MODE)
	XI_BIN_MODE xiAPIplus_Camera::GetBinningVerticalMode()
	{
		int val=0;
		
		CheckCamHandle("GetBinningVerticalMode");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_VERTICAL_MODE, &val);
		CheckResult(res,"GetBinningVerticalMode");
		return (XI_BIN_MODE)val;
	}
	
	XI_BIN_MODE xiAPIplus_Camera::GetBinningVerticalMode_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetBinningVerticalMode" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_VERTICAL_MODE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetBinningVerticalMode" "_Maximum");
		return (XI_BIN_MODE)val;
	}
	
	XI_BIN_MODE xiAPIplus_Camera::GetBinningVerticalMode_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetBinningVerticalMode" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_VERTICAL_MODE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetBinningVerticalMode" "_Minimum");
		return (XI_BIN_MODE)val;
	}
	
	int xiAPIplus_Camera::GetBinningVerticalMode_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetBinningVerticalMode" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_VERTICAL_MODE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetBinningVerticalMode" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetBinningVerticalMode(XI_BIN_MODE BinningVerticalMode)
	{
		
		CheckCamHandleInt("SetBinningVerticalMode",(int)BinningVerticalMode);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_BINNING_VERTICAL_MODE, BinningVerticalMode);
		CheckResult(res,"SetBinningVerticalMode");
	}
	 
	
	// Vertical Binning - number of vertical photo-sensitive cells to combine together. (XI_PRM_BINNING_VERTICAL)
	// integer type
	int xiAPIplus_Camera::GetBinningVertical()
	{
		CheckCamHandle("GetBinningVertical");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_VERTICAL, &val);
		CheckResult(res,"GetBinningVertical");
		return val;	
	}
	int xiAPIplus_Camera::GetBinningVertical_Maximum()
	{		
		CheckCamHandle("GetBinningVertical" "_Maximum");
		int val=0;
		CheckCamHandle("GetBinningVertical");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_VERTICAL XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetBinningVertical" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetBinningVertical_Minimum()
	{
		CheckCamHandle("GetBinningVertical" "_Minimum");
		int val=0;
		CheckCamHandle("GetBinningVertical");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_VERTICAL XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetBinningVertical" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetBinningVertical_Increment()
	{
		CheckCamHandle("GetBinningVertical" "_Increment");
		int val=0;
		CheckCamHandle("GetBinningVertical");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_VERTICAL XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetBinningVertical" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetBinningVertical(int BinningVertical)
	{
		
		CheckCamHandleInt("SetBinningVertical",BinningVertical);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_BINNING_VERTICAL, BinningVertical);
		CheckResult(res,"SetBinningVertical");
	}
	 
	
	// Sets the mode to use to combine horizontal pixel together. (XI_PRM_BINNING_HORIZONTAL_MODE)
	XI_BIN_MODE xiAPIplus_Camera::GetBinningHorizontalMode()
	{
		int val=0;
		
		CheckCamHandle("GetBinningHorizontalMode");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_HORIZONTAL_MODE, &val);
		CheckResult(res,"GetBinningHorizontalMode");
		return (XI_BIN_MODE)val;
	}
	
	XI_BIN_MODE xiAPIplus_Camera::GetBinningHorizontalMode_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetBinningHorizontalMode" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_HORIZONTAL_MODE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetBinningHorizontalMode" "_Maximum");
		return (XI_BIN_MODE)val;
	}
	
	XI_BIN_MODE xiAPIplus_Camera::GetBinningHorizontalMode_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetBinningHorizontalMode" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_HORIZONTAL_MODE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetBinningHorizontalMode" "_Minimum");
		return (XI_BIN_MODE)val;
	}
	
	int xiAPIplus_Camera::GetBinningHorizontalMode_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetBinningHorizontalMode" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_HORIZONTAL_MODE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetBinningHorizontalMode" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetBinningHorizontalMode(XI_BIN_MODE BinningHorizontalMode)
	{
		
		CheckCamHandleInt("SetBinningHorizontalMode",(int)BinningHorizontalMode);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_BINNING_HORIZONTAL_MODE, BinningHorizontalMode);
		CheckResult(res,"SetBinningHorizontalMode");
	}
	 
	
	// Horizontal Binning - number of horizontal photo-sensitive cells to combine together. (XI_PRM_BINNING_HORIZONTAL)
	// integer type
	int xiAPIplus_Camera::GetBinningHorizontal()
	{
		CheckCamHandle("GetBinningHorizontal");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_HORIZONTAL, &val);
		CheckResult(res,"GetBinningHorizontal");
		return val;	
	}
	int xiAPIplus_Camera::GetBinningHorizontal_Maximum()
	{		
		CheckCamHandle("GetBinningHorizontal" "_Maximum");
		int val=0;
		CheckCamHandle("GetBinningHorizontal");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_HORIZONTAL XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetBinningHorizontal" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetBinningHorizontal_Minimum()
	{
		CheckCamHandle("GetBinningHorizontal" "_Minimum");
		int val=0;
		CheckCamHandle("GetBinningHorizontal");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_HORIZONTAL XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetBinningHorizontal" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetBinningHorizontal_Increment()
	{
		CheckCamHandle("GetBinningHorizontal" "_Increment");
		int val=0;
		CheckCamHandle("GetBinningHorizontal");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_HORIZONTAL XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetBinningHorizontal" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetBinningHorizontal(int BinningHorizontal)
	{
		
		CheckCamHandleInt("SetBinningHorizontal",BinningHorizontal);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_BINNING_HORIZONTAL, BinningHorizontal);
		CheckResult(res,"SetBinningHorizontal");
	}
	 
	
	// Binning horizontal pattern type. (XI_PRM_BINNING_HORIZONTAL_PATTERN)
	XI_BIN_PATTERN xiAPIplus_Camera::GetBinningHorizontalPattern()
	{
		int val=0;
		
		CheckCamHandle("GetBinningHorizontalPattern");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_HORIZONTAL_PATTERN, &val);
		CheckResult(res,"GetBinningHorizontalPattern");
		return (XI_BIN_PATTERN)val;
	}
	
	XI_BIN_PATTERN xiAPIplus_Camera::GetBinningHorizontalPattern_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetBinningHorizontalPattern" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_HORIZONTAL_PATTERN XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetBinningHorizontalPattern" "_Maximum");
		return (XI_BIN_PATTERN)val;
	}
	
	XI_BIN_PATTERN xiAPIplus_Camera::GetBinningHorizontalPattern_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetBinningHorizontalPattern" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_HORIZONTAL_PATTERN XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetBinningHorizontalPattern" "_Minimum");
		return (XI_BIN_PATTERN)val;
	}
	
	int xiAPIplus_Camera::GetBinningHorizontalPattern_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetBinningHorizontalPattern" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_HORIZONTAL_PATTERN XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetBinningHorizontalPattern" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetBinningHorizontalPattern(XI_BIN_PATTERN BinningHorizontalPattern)
	{
		
		CheckCamHandleInt("SetBinningHorizontalPattern",(int)BinningHorizontalPattern);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_BINNING_HORIZONTAL_PATTERN, BinningHorizontalPattern);
		CheckResult(res,"SetBinningHorizontalPattern");
	}
	 
	
	// Binning vertical pattern type. (XI_PRM_BINNING_VERTICAL_PATTERN)
	XI_BIN_PATTERN xiAPIplus_Camera::GetBinningVerticalPattern()
	{
		int val=0;
		
		CheckCamHandle("GetBinningVerticalPattern");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_VERTICAL_PATTERN, &val);
		CheckResult(res,"GetBinningVerticalPattern");
		return (XI_BIN_PATTERN)val;
	}
	
	XI_BIN_PATTERN xiAPIplus_Camera::GetBinningVerticalPattern_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetBinningVerticalPattern" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_VERTICAL_PATTERN XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetBinningVerticalPattern" "_Maximum");
		return (XI_BIN_PATTERN)val;
	}
	
	XI_BIN_PATTERN xiAPIplus_Camera::GetBinningVerticalPattern_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetBinningVerticalPattern" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_VERTICAL_PATTERN XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetBinningVerticalPattern" "_Minimum");
		return (XI_BIN_PATTERN)val;
	}
	
	int xiAPIplus_Camera::GetBinningVerticalPattern_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetBinningVerticalPattern" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BINNING_VERTICAL_PATTERN XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetBinningVerticalPattern" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetBinningVerticalPattern(XI_BIN_PATTERN BinningVerticalPattern)
	{
		
		CheckCamHandleInt("SetBinningVerticalPattern",(int)BinningVerticalPattern);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_BINNING_VERTICAL_PATTERN, BinningVerticalPattern);
		CheckResult(res,"SetBinningVerticalPattern");
	}
	 
	
	// Decimation engine selector. (XI_PRM_DECIMATION_SELECTOR)
	XI_DEC_SELECTOR xiAPIplus_Camera::GetDecimationSelector()
	{
		int val=0;
		
		CheckCamHandle("GetDecimationSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_SELECTOR, &val);
		CheckResult(res,"GetDecimationSelector");
		return (XI_DEC_SELECTOR)val;
	}
	
	XI_DEC_SELECTOR xiAPIplus_Camera::GetDecimationSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetDecimationSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDecimationSelector" "_Maximum");
		return (XI_DEC_SELECTOR)val;
	}
	
	XI_DEC_SELECTOR xiAPIplus_Camera::GetDecimationSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetDecimationSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDecimationSelector" "_Minimum");
		return (XI_DEC_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetDecimationSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetDecimationSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDecimationSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetDecimationSelector(XI_DEC_SELECTOR DecimationSelector)
	{
		
		CheckCamHandleInt("SetDecimationSelector",(int)DecimationSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DECIMATION_SELECTOR, DecimationSelector);
		CheckResult(res,"SetDecimationSelector");
	}
	 
	
	// Vertical Decimation - vertical sub-sampling of the image - reduces the vertical resolution of the image by the specified vertical decimation factor. (XI_PRM_DECIMATION_VERTICAL)
	// integer type
	int xiAPIplus_Camera::GetDecimationVertical()
	{
		CheckCamHandle("GetDecimationVertical");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_VERTICAL, &val);
		CheckResult(res,"GetDecimationVertical");
		return val;	
	}
	int xiAPIplus_Camera::GetDecimationVertical_Maximum()
	{		
		CheckCamHandle("GetDecimationVertical" "_Maximum");
		int val=0;
		CheckCamHandle("GetDecimationVertical");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_VERTICAL XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDecimationVertical" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetDecimationVertical_Minimum()
	{
		CheckCamHandle("GetDecimationVertical" "_Minimum");
		int val=0;
		CheckCamHandle("GetDecimationVertical");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_VERTICAL XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDecimationVertical" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetDecimationVertical_Increment()
	{
		CheckCamHandle("GetDecimationVertical" "_Increment");
		int val=0;
		CheckCamHandle("GetDecimationVertical");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_VERTICAL XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDecimationVertical" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetDecimationVertical(int DecimationVertical)
	{
		
		CheckCamHandleInt("SetDecimationVertical",DecimationVertical);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DECIMATION_VERTICAL, DecimationVertical);
		CheckResult(res,"SetDecimationVertical");
	}
	 
	
	// Horizontal Decimation - horizontal sub-sampling of the image - reduces the horizontal resolution of the image by the specified vertical decimation factor. (XI_PRM_DECIMATION_HORIZONTAL)
	// integer type
	int xiAPIplus_Camera::GetDecimationHorizontal()
	{
		CheckCamHandle("GetDecimationHorizontal");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_HORIZONTAL, &val);
		CheckResult(res,"GetDecimationHorizontal");
		return val;	
	}
	int xiAPIplus_Camera::GetDecimationHorizontal_Maximum()
	{		
		CheckCamHandle("GetDecimationHorizontal" "_Maximum");
		int val=0;
		CheckCamHandle("GetDecimationHorizontal");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_HORIZONTAL XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDecimationHorizontal" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetDecimationHorizontal_Minimum()
	{
		CheckCamHandle("GetDecimationHorizontal" "_Minimum");
		int val=0;
		CheckCamHandle("GetDecimationHorizontal");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_HORIZONTAL XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDecimationHorizontal" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetDecimationHorizontal_Increment()
	{
		CheckCamHandle("GetDecimationHorizontal" "_Increment");
		int val=0;
		CheckCamHandle("GetDecimationHorizontal");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_HORIZONTAL XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDecimationHorizontal" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetDecimationHorizontal(int DecimationHorizontal)
	{
		
		CheckCamHandleInt("SetDecimationHorizontal",DecimationHorizontal);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DECIMATION_HORIZONTAL, DecimationHorizontal);
		CheckResult(res,"SetDecimationHorizontal");
	}
	 
	
	// Decimation horizontal pattern type. (XI_PRM_DECIMATION_HORIZONTAL_PATTERN)
	XI_DEC_PATTERN xiAPIplus_Camera::GetDecimationHorizontalPattern()
	{
		int val=0;
		
		CheckCamHandle("GetDecimationHorizontalPattern");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_HORIZONTAL_PATTERN, &val);
		CheckResult(res,"GetDecimationHorizontalPattern");
		return (XI_DEC_PATTERN)val;
	}
	
	XI_DEC_PATTERN xiAPIplus_Camera::GetDecimationHorizontalPattern_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetDecimationHorizontalPattern" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_HORIZONTAL_PATTERN XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDecimationHorizontalPattern" "_Maximum");
		return (XI_DEC_PATTERN)val;
	}
	
	XI_DEC_PATTERN xiAPIplus_Camera::GetDecimationHorizontalPattern_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetDecimationHorizontalPattern" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_HORIZONTAL_PATTERN XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDecimationHorizontalPattern" "_Minimum");
		return (XI_DEC_PATTERN)val;
	}
	
	int xiAPIplus_Camera::GetDecimationHorizontalPattern_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetDecimationHorizontalPattern" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_HORIZONTAL_PATTERN XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDecimationHorizontalPattern" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetDecimationHorizontalPattern(XI_DEC_PATTERN DecimationHorizontalPattern)
	{
		
		CheckCamHandleInt("SetDecimationHorizontalPattern",(int)DecimationHorizontalPattern);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DECIMATION_HORIZONTAL_PATTERN, DecimationHorizontalPattern);
		CheckResult(res,"SetDecimationHorizontalPattern");
	}
	 
	
	// Decimation vertical pattern type. (XI_PRM_DECIMATION_VERTICAL_PATTERN)
	XI_DEC_PATTERN xiAPIplus_Camera::GetDecimationVerticalPattern()
	{
		int val=0;
		
		CheckCamHandle("GetDecimationVerticalPattern");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_VERTICAL_PATTERN, &val);
		CheckResult(res,"GetDecimationVerticalPattern");
		return (XI_DEC_PATTERN)val;
	}
	
	XI_DEC_PATTERN xiAPIplus_Camera::GetDecimationVerticalPattern_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetDecimationVerticalPattern" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_VERTICAL_PATTERN XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDecimationVerticalPattern" "_Maximum");
		return (XI_DEC_PATTERN)val;
	}
	
	XI_DEC_PATTERN xiAPIplus_Camera::GetDecimationVerticalPattern_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetDecimationVerticalPattern" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_VERTICAL_PATTERN XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDecimationVerticalPattern" "_Minimum");
		return (XI_DEC_PATTERN)val;
	}
	
	int xiAPIplus_Camera::GetDecimationVerticalPattern_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetDecimationVerticalPattern" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DECIMATION_VERTICAL_PATTERN XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDecimationVerticalPattern" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetDecimationVerticalPattern(XI_DEC_PATTERN DecimationVerticalPattern)
	{
		
		CheckCamHandleInt("SetDecimationVerticalPattern",(int)DecimationVerticalPattern);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DECIMATION_VERTICAL_PATTERN, DecimationVerticalPattern);
		CheckResult(res,"SetDecimationVerticalPattern");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: AE Setup
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Exposure priority (0.8 - exposure 80%, gain 20%). (XI_PRM_EXP_PRIORITY)
	float xiAPIplus_Camera::GetAutoExposureAutoGainExposurePriority()
	{
		float val=0;
		
		CheckCamHandle("GetAutoExposureAutoGainExposurePriority");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_EXP_PRIORITY, &val);
		CheckResult(res,"GetAutoExposureAutoGainExposurePriority");
		return val;
	}

	float xiAPIplus_Camera::GetAutoExposureAutoGainExposurePriority_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetAutoExposureAutoGainExposurePriority" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_EXP_PRIORITY XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAutoExposureAutoGainExposurePriority" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetAutoExposureAutoGainExposurePriority_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetAutoExposureAutoGainExposurePriority" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_EXP_PRIORITY XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAutoExposureAutoGainExposurePriority" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetAutoExposureAutoGainExposurePriority_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetAutoExposureAutoGainExposurePriority" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_EXP_PRIORITY XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAutoExposureAutoGainExposurePriority" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetAutoExposureAutoGainExposurePriority(float AutoExposureAutoGainExposurePriority)
	{
		
		CheckCamHandle("SetAutoExposureAutoGainExposurePriority");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_EXP_PRIORITY, AutoExposureAutoGainExposurePriority);
		CheckResult(res,"SetAutoExposureAutoGainExposurePriority");
	}
	 
	
	// Maximum limit of gain in AEAG procedure (XI_PRM_AG_MAX_LIMIT)
	float xiAPIplus_Camera::GetAutoGainTopLimit()
	{
		float val=0;
		
		CheckCamHandle("GetAutoGainTopLimit");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_AG_MAX_LIMIT, &val);
		CheckResult(res,"GetAutoGainTopLimit");
		return val;
	}

	float xiAPIplus_Camera::GetAutoGainTopLimit_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetAutoGainTopLimit" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_AG_MAX_LIMIT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAutoGainTopLimit" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetAutoGainTopLimit_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetAutoGainTopLimit" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_AG_MAX_LIMIT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAutoGainTopLimit" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetAutoGainTopLimit_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetAutoGainTopLimit" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_AG_MAX_LIMIT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAutoGainTopLimit" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetAutoGainTopLimit(float AutoGainTopLimit)
	{
		
		CheckCamHandle("SetAutoGainTopLimit");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_AG_MAX_LIMIT, AutoGainTopLimit);
		CheckResult(res,"SetAutoGainTopLimit");
	}
	 
	
	// Maximum time (us) used for exposure in AEAG procedure (XI_PRM_AE_MAX_LIMIT)
	// integer type
	int xiAPIplus_Camera::GetAutoExposureTopLimit()
	{
		CheckCamHandle("GetAutoExposureTopLimit");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AE_MAX_LIMIT, &val);
		CheckResult(res,"GetAutoExposureTopLimit");
		return val;	
	}
	int xiAPIplus_Camera::GetAutoExposureTopLimit_Maximum()
	{		
		CheckCamHandle("GetAutoExposureTopLimit" "_Maximum");
		int val=0;
		CheckCamHandle("GetAutoExposureTopLimit");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AE_MAX_LIMIT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAutoExposureTopLimit" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetAutoExposureTopLimit_Minimum()
	{
		CheckCamHandle("GetAutoExposureTopLimit" "_Minimum");
		int val=0;
		CheckCamHandle("GetAutoExposureTopLimit");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AE_MAX_LIMIT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAutoExposureTopLimit" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetAutoExposureTopLimit_Increment()
	{
		CheckCamHandle("GetAutoExposureTopLimit" "_Increment");
		int val=0;
		CheckCamHandle("GetAutoExposureTopLimit");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AE_MAX_LIMIT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAutoExposureTopLimit" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetAutoExposureTopLimit(int AutoExposureTopLimit)
	{
		
		CheckCamHandleInt("SetAutoExposureTopLimit",AutoExposureTopLimit);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_AE_MAX_LIMIT, AutoExposureTopLimit);
		CheckResult(res,"SetAutoExposureTopLimit");
	}
	 
	
	// Average intensity of output signal AEAG should achieve(in %) (XI_PRM_AEAG_LEVEL)
	// integer type
	int xiAPIplus_Camera::GetAutoExposureAutoGainTargetLevel()
	{
		CheckCamHandle("GetAutoExposureAutoGainTargetLevel");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_LEVEL, &val);
		CheckResult(res,"GetAutoExposureAutoGainTargetLevel");
		return val;	
	}
	int xiAPIplus_Camera::GetAutoExposureAutoGainTargetLevel_Maximum()
	{		
		CheckCamHandle("GetAutoExposureAutoGainTargetLevel" "_Maximum");
		int val=0;
		CheckCamHandle("GetAutoExposureAutoGainTargetLevel");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_LEVEL XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAutoExposureAutoGainTargetLevel" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetAutoExposureAutoGainTargetLevel_Minimum()
	{
		CheckCamHandle("GetAutoExposureAutoGainTargetLevel" "_Minimum");
		int val=0;
		CheckCamHandle("GetAutoExposureAutoGainTargetLevel");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_LEVEL XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAutoExposureAutoGainTargetLevel" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetAutoExposureAutoGainTargetLevel_Increment()
	{
		CheckCamHandle("GetAutoExposureAutoGainTargetLevel" "_Increment");
		int val=0;
		CheckCamHandle("GetAutoExposureAutoGainTargetLevel");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AEAG_LEVEL XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAutoExposureAutoGainTargetLevel" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetAutoExposureAutoGainTargetLevel(int AutoExposureAutoGainTargetLevel)
	{
		
		CheckCamHandleInt("SetAutoExposureAutoGainTargetLevel",AutoExposureAutoGainTargetLevel);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_AEAG_LEVEL, AutoExposureAutoGainTargetLevel);
		CheckResult(res,"SetAutoExposureAutoGainTargetLevel");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Performance
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Set/get bandwidth(data rate in Megabits) (XI_PRM_LIMIT_BANDWIDTH)
	// integer type
	int xiAPIplus_Camera::GetBandwidthLimit()
	{
		CheckCamHandle("GetBandwidthLimit");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LIMIT_BANDWIDTH, &val);
		CheckResult(res,"GetBandwidthLimit");
		return val;	
	}
	int xiAPIplus_Camera::GetBandwidthLimit_Maximum()
	{		
		CheckCamHandle("GetBandwidthLimit" "_Maximum");
		int val=0;
		CheckCamHandle("GetBandwidthLimit");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LIMIT_BANDWIDTH XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetBandwidthLimit" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetBandwidthLimit_Minimum()
	{
		CheckCamHandle("GetBandwidthLimit" "_Minimum");
		int val=0;
		CheckCamHandle("GetBandwidthLimit");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LIMIT_BANDWIDTH XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetBandwidthLimit" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetBandwidthLimit_Increment()
	{
		CheckCamHandle("GetBandwidthLimit" "_Increment");
		int val=0;
		CheckCamHandle("GetBandwidthLimit");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LIMIT_BANDWIDTH XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetBandwidthLimit" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetBandwidthLimit(int BandwidthLimit)
	{
		
		CheckCamHandleInt("SetBandwidthLimit",BandwidthLimit);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_LIMIT_BANDWIDTH, BandwidthLimit);
		CheckResult(res,"SetBandwidthLimit");
	}
	 
	
	// Bandwidth limit enabled (XI_PRM_LIMIT_BANDWIDTH_MODE)
	XI_SWITCH xiAPIplus_Camera::GetBandwidthLimitMode()
	{
		int val=0;
		
		CheckCamHandle("GetBandwidthLimitMode");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LIMIT_BANDWIDTH_MODE, &val);
		CheckResult(res,"GetBandwidthLimitMode");
		return (XI_SWITCH)val;
	}
	
	XI_SWITCH xiAPIplus_Camera::GetBandwidthLimitMode_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetBandwidthLimitMode" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LIMIT_BANDWIDTH_MODE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetBandwidthLimitMode" "_Maximum");
		return (XI_SWITCH)val;
	}
	
	XI_SWITCH xiAPIplus_Camera::GetBandwidthLimitMode_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetBandwidthLimitMode" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LIMIT_BANDWIDTH_MODE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetBandwidthLimitMode" "_Minimum");
		return (XI_SWITCH)val;
	}
	
	int xiAPIplus_Camera::GetBandwidthLimitMode_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetBandwidthLimitMode" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LIMIT_BANDWIDTH_MODE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetBandwidthLimitMode" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetBandwidthLimitMode(XI_SWITCH BandwidthLimitMode)
	{
		
		CheckCamHandleInt("SetBandwidthLimitMode",(int)BandwidthLimitMode);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_LIMIT_BANDWIDTH_MODE, BandwidthLimitMode);
		CheckResult(res,"SetBandwidthLimitMode");
	}
	 
	
	// Sensor output data bit depth. (XI_PRM_SENSOR_DATA_BIT_DEPTH)
	XI_BIT_DEPTH xiAPIplus_Camera::GetSensorDataBitDepth()
	{
		int val=0;
		
		CheckCamHandle("GetSensorDataBitDepth");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_DATA_BIT_DEPTH, &val);
		CheckResult(res,"GetSensorDataBitDepth");
		return (XI_BIT_DEPTH)val;
	}
	
	XI_BIT_DEPTH xiAPIplus_Camera::GetSensorDataBitDepth_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetSensorDataBitDepth" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_DATA_BIT_DEPTH XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetSensorDataBitDepth" "_Maximum");
		return (XI_BIT_DEPTH)val;
	}
	
	XI_BIT_DEPTH xiAPIplus_Camera::GetSensorDataBitDepth_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetSensorDataBitDepth" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_DATA_BIT_DEPTH XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetSensorDataBitDepth" "_Minimum");
		return (XI_BIT_DEPTH)val;
	}
	
	int xiAPIplus_Camera::GetSensorDataBitDepth_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetSensorDataBitDepth" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_DATA_BIT_DEPTH XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetSensorDataBitDepth" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetSensorDataBitDepth(XI_BIT_DEPTH SensorDataBitDepth)
	{
		
		CheckCamHandleInt("SetSensorDataBitDepth",(int)SensorDataBitDepth);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_SENSOR_DATA_BIT_DEPTH, SensorDataBitDepth);
		CheckResult(res,"SetSensorDataBitDepth");
	}
	 
	
	// Device output data bit depth. (XI_PRM_OUTPUT_DATA_BIT_DEPTH)
	XI_BIT_DEPTH xiAPIplus_Camera::GetDeviceOutputDataBitDepth()
	{
		int val=0;
		
		CheckCamHandle("GetDeviceOutputDataBitDepth");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OUTPUT_DATA_BIT_DEPTH, &val);
		CheckResult(res,"GetDeviceOutputDataBitDepth");
		return (XI_BIT_DEPTH)val;
	}
	
	XI_BIT_DEPTH xiAPIplus_Camera::GetDeviceOutputDataBitDepth_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetDeviceOutputDataBitDepth" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OUTPUT_DATA_BIT_DEPTH XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDeviceOutputDataBitDepth" "_Maximum");
		return (XI_BIT_DEPTH)val;
	}
	
	XI_BIT_DEPTH xiAPIplus_Camera::GetDeviceOutputDataBitDepth_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetDeviceOutputDataBitDepth" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OUTPUT_DATA_BIT_DEPTH XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDeviceOutputDataBitDepth" "_Minimum");
		return (XI_BIT_DEPTH)val;
	}
	
	int xiAPIplus_Camera::GetDeviceOutputDataBitDepth_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetDeviceOutputDataBitDepth" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OUTPUT_DATA_BIT_DEPTH XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDeviceOutputDataBitDepth" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetDeviceOutputDataBitDepth(XI_BIT_DEPTH DeviceOutputDataBitDepth)
	{
		
		CheckCamHandleInt("SetDeviceOutputDataBitDepth",(int)DeviceOutputDataBitDepth);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_OUTPUT_DATA_BIT_DEPTH, DeviceOutputDataBitDepth);
		CheckResult(res,"SetDeviceOutputDataBitDepth");
	}
	 
	
	// bit depth of data returned by function xiGetImage (XI_PRM_IMAGE_DATA_BIT_DEPTH)
	XI_BIT_DEPTH xiAPIplus_Camera::GetImageDataBitDepth()
	{
		int val=0;
		
		CheckCamHandle("GetImageDataBitDepth");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_DATA_BIT_DEPTH, &val);
		CheckResult(res,"GetImageDataBitDepth");
		return (XI_BIT_DEPTH)val;
	}
	
	XI_BIT_DEPTH xiAPIplus_Camera::GetImageDataBitDepth_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetImageDataBitDepth" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_DATA_BIT_DEPTH XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetImageDataBitDepth" "_Maximum");
		return (XI_BIT_DEPTH)val;
	}
	
	XI_BIT_DEPTH xiAPIplus_Camera::GetImageDataBitDepth_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetImageDataBitDepth" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_DATA_BIT_DEPTH XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetImageDataBitDepth" "_Minimum");
		return (XI_BIT_DEPTH)val;
	}
	
	int xiAPIplus_Camera::GetImageDataBitDepth_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetImageDataBitDepth" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_DATA_BIT_DEPTH XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetImageDataBitDepth" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetImageDataBitDepth(XI_BIT_DEPTH ImageDataBitDepth)
	{
		
		CheckCamHandleInt("SetImageDataBitDepth",(int)ImageDataBitDepth);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_IMAGE_DATA_BIT_DEPTH, ImageDataBitDepth);
		CheckResult(res,"SetImageDataBitDepth");
	}
	 
	
	// Device output data packing (or grouping) enabled. Packing could be enabled if output_data_bit_depth > 8 and packing capability is available. (XI_PRM_OUTPUT_DATA_PACKING)
	bool xiAPIplus_Camera::IsDeviceOutputDataPacking()
	{
		int val=0;
		
		CheckCamHandle("IsDeviceOutputDataPacking");
		
		xiGetParamInt(camera_handle, XI_PRM_OUTPUT_DATA_PACKING, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableDeviceOutputDataPacking()
	{
		
		CheckCamHandle("IsDeviceOutputDataPacking");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_OUTPUT_DATA_PACKING, XI_ON);
		CheckResult(res,"EnableDeviceOutputDataPacking");
	}

	void xiAPIplus_Camera::DisableDeviceOutputDataPacking()
	{
		
		CheckCamHandle("DisableDeviceOutputDataPacking");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_OUTPUT_DATA_PACKING, XI_OFF);
		CheckResult(res,"DisableDeviceOutputDataPacking");
	}	
	 
	
	// Data packing type. Some cameras supports only specific packing type. (XI_PRM_OUTPUT_DATA_PACKING_TYPE)
	XI_OUTPUT_DATA_PACKING_TYPE xiAPIplus_Camera::GetDeviceOutputDataPackingType()
	{
		int val=0;
		
		CheckCamHandle("GetDeviceOutputDataPackingType");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OUTPUT_DATA_PACKING_TYPE, &val);
		CheckResult(res,"GetDeviceOutputDataPackingType");
		return (XI_OUTPUT_DATA_PACKING_TYPE)val;
	}
	
	XI_OUTPUT_DATA_PACKING_TYPE xiAPIplus_Camera::GetDeviceOutputDataPackingType_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetDeviceOutputDataPackingType" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OUTPUT_DATA_PACKING_TYPE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDeviceOutputDataPackingType" "_Maximum");
		return (XI_OUTPUT_DATA_PACKING_TYPE)val;
	}
	
	XI_OUTPUT_DATA_PACKING_TYPE xiAPIplus_Camera::GetDeviceOutputDataPackingType_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetDeviceOutputDataPackingType" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OUTPUT_DATA_PACKING_TYPE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDeviceOutputDataPackingType" "_Minimum");
		return (XI_OUTPUT_DATA_PACKING_TYPE)val;
	}
	
	int xiAPIplus_Camera::GetDeviceOutputDataPackingType_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetDeviceOutputDataPackingType" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_OUTPUT_DATA_PACKING_TYPE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDeviceOutputDataPackingType" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetDeviceOutputDataPackingType(XI_OUTPUT_DATA_PACKING_TYPE DeviceOutputDataPackingType)
	{
		
		CheckCamHandleInt("SetDeviceOutputDataPackingType",(int)DeviceOutputDataPackingType);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_OUTPUT_DATA_PACKING_TYPE, DeviceOutputDataPackingType);
		CheckResult(res,"SetDeviceOutputDataPackingType");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Temperature
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Returns 1 for cameras that support cooling. (XI_PRM_IS_COOLED)
	bool xiAPIplus_Camera::IsCooled()
	{
		int val=0;
		
		CheckCamHandle("IsCooled");
		
		xiGetParamInt(camera_handle, XI_PRM_IS_COOLED, &val);
		return (val!=0);
	}
	 
	
	// Temperature control mode. (XI_PRM_COOLING)
	XI_TEMP_CTRL_MODE_SELECTOR xiAPIplus_Camera::GetCooling()
	{
		int val=0;
		
		CheckCamHandle("GetCooling");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COOLING, &val);
		CheckResult(res,"GetCooling");
		return (XI_TEMP_CTRL_MODE_SELECTOR)val;
	}
	
	XI_TEMP_CTRL_MODE_SELECTOR xiAPIplus_Camera::GetCooling_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetCooling" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COOLING XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetCooling" "_Maximum");
		return (XI_TEMP_CTRL_MODE_SELECTOR)val;
	}
	
	XI_TEMP_CTRL_MODE_SELECTOR xiAPIplus_Camera::GetCooling_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetCooling" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COOLING XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetCooling" "_Minimum");
		return (XI_TEMP_CTRL_MODE_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetCooling_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetCooling" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COOLING XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetCooling" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetCooling(XI_TEMP_CTRL_MODE_SELECTOR Cooling)
	{
		
		CheckCamHandleInt("SetCooling",(int)Cooling);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_COOLING, Cooling);
		CheckResult(res,"SetCooling");
	}
	 
	
	// Set sensor target temperature for cooling. (XI_PRM_TARGET_TEMP)
	float xiAPIplus_Camera::GetTargetTemperature()
	{
		float val=0;
		
		CheckCamHandle("GetTargetTemperature");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_TARGET_TEMP, &val);
		CheckResult(res,"GetTargetTemperature");
		return val;
	}

	float xiAPIplus_Camera::GetTargetTemperature_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetTargetTemperature" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_TARGET_TEMP XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTargetTemperature" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetTargetTemperature_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetTargetTemperature" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_TARGET_TEMP XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTargetTemperature" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetTargetTemperature_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetTargetTemperature" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_TARGET_TEMP XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTargetTemperature" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetTargetTemperature(float TargetTemperature)
	{
		
		CheckCamHandle("SetTargetTemperature");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_TARGET_TEMP, TargetTemperature);
		CheckResult(res,"SetTargetTemperature");
	}
	 
	
	// Selector of mechanical point where thermometer is located. (XI_PRM_TEMP_SELECTOR)
	XI_TEMP_SELECTOR xiAPIplus_Camera::GetTemperatureSelector()
	{
		int val=0;
		
		CheckCamHandle("GetTemperatureSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEMP_SELECTOR, &val);
		CheckResult(res,"GetTemperatureSelector");
		return (XI_TEMP_SELECTOR)val;
	}
	
	XI_TEMP_SELECTOR xiAPIplus_Camera::GetTemperatureSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetTemperatureSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEMP_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTemperatureSelector" "_Maximum");
		return (XI_TEMP_SELECTOR)val;
	}
	
	XI_TEMP_SELECTOR xiAPIplus_Camera::GetTemperatureSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetTemperatureSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEMP_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTemperatureSelector" "_Minimum");
		return (XI_TEMP_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetTemperatureSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetTemperatureSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEMP_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTemperatureSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetTemperatureSelector(XI_TEMP_SELECTOR TemperatureSelector)
	{
		
		CheckCamHandleInt("SetTemperatureSelector",(int)TemperatureSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_TEMP_SELECTOR, TemperatureSelector);
		CheckResult(res,"SetTemperatureSelector");
	}
	 
	
	// Camera temperature (selected by XI_PRM_TEMP_SELECTOR) (XI_PRM_TEMP)
	float xiAPIplus_Camera::GetTemperature()
	{
		float val=0;
		
		CheckCamHandle("GetTemperature");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_TEMP, &val);
		CheckResult(res,"GetTemperature");
		return val;
	}

	float xiAPIplus_Camera::GetTemperature_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetTemperature" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_TEMP XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTemperature" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetTemperature_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetTemperature" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_TEMP XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTemperature" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetTemperature_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetTemperature" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_TEMP XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTemperature" "_Increment");
		return val;
	}
	 
	
	// Temperature control mode. (XI_PRM_TEMP_CONTROL_MODE)
	XI_TEMP_CTRL_MODE_SELECTOR xiAPIplus_Camera::GetTemperatureControlMode()
	{
		int val=0;
		
		CheckCamHandle("GetTemperatureControlMode");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEMP_CONTROL_MODE, &val);
		CheckResult(res,"GetTemperatureControlMode");
		return (XI_TEMP_CTRL_MODE_SELECTOR)val;
	}
	
	XI_TEMP_CTRL_MODE_SELECTOR xiAPIplus_Camera::GetTemperatureControlMode_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetTemperatureControlMode" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEMP_CONTROL_MODE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTemperatureControlMode" "_Maximum");
		return (XI_TEMP_CTRL_MODE_SELECTOR)val;
	}
	
	XI_TEMP_CTRL_MODE_SELECTOR xiAPIplus_Camera::GetTemperatureControlMode_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetTemperatureControlMode" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEMP_CONTROL_MODE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTemperatureControlMode" "_Minimum");
		return (XI_TEMP_CTRL_MODE_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetTemperatureControlMode_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetTemperatureControlMode" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEMP_CONTROL_MODE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTemperatureControlMode" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetTemperatureControlMode(XI_TEMP_CTRL_MODE_SELECTOR TemperatureControlMode)
	{
		
		CheckCamHandleInt("SetTemperatureControlMode",(int)TemperatureControlMode);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_TEMP_CONTROL_MODE, TemperatureControlMode);
		CheckResult(res,"SetTemperatureControlMode");
	}
	 
	
	// Camera sensor temperature (XI_PRM_CHIP_TEMP)
	float xiAPIplus_Camera::GetTemperatureSensor()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureSensor");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CHIP_TEMP, &val);
		CheckResult(res,"GetTemperatureSensor");
		return val;
	}

	float xiAPIplus_Camera::GetTemperatureSensor_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureSensor" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CHIP_TEMP XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTemperatureSensor" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetTemperatureSensor_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureSensor" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CHIP_TEMP XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTemperatureSensor" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetTemperatureSensor_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureSensor" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CHIP_TEMP XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTemperatureSensor" "_Increment");
		return val;
	}
	 
	
	// Camera housing temperature (XI_PRM_HOUS_TEMP)
	float xiAPIplus_Camera::GetTemperatureHousing()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureHousing");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_HOUS_TEMP, &val);
		CheckResult(res,"GetTemperatureHousing");
		return val;
	}

	float xiAPIplus_Camera::GetTemperatureHousing_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureHousing" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_HOUS_TEMP XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTemperatureHousing" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetTemperatureHousing_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureHousing" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_HOUS_TEMP XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTemperatureHousing" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetTemperatureHousing_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureHousing" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_HOUS_TEMP XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTemperatureHousing" "_Increment");
		return val;
	}
	 
	
	// Camera housing back side temperature (XI_PRM_HOUS_BACK_SIDE_TEMP)
	float xiAPIplus_Camera::GetTemperatureHousingBackSide()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureHousingBackSide");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_HOUS_BACK_SIDE_TEMP, &val);
		CheckResult(res,"GetTemperatureHousingBackSide");
		return val;
	}

	float xiAPIplus_Camera::GetTemperatureHousingBackSide_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureHousingBackSide" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_HOUS_BACK_SIDE_TEMP XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTemperatureHousingBackSide" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetTemperatureHousingBackSide_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureHousingBackSide" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_HOUS_BACK_SIDE_TEMP XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTemperatureHousingBackSide" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetTemperatureHousingBackSide_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureHousingBackSide" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_HOUS_BACK_SIDE_TEMP XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTemperatureHousingBackSide" "_Increment");
		return val;
	}
	 
	
	// Camera sensor board temperature (XI_PRM_SENSOR_BOARD_TEMP)
	float xiAPIplus_Camera::GetTemperatureSensorBoard()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureSensorBoard");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_SENSOR_BOARD_TEMP, &val);
		CheckResult(res,"GetTemperatureSensorBoard");
		return val;
	}

	float xiAPIplus_Camera::GetTemperatureSensorBoard_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureSensorBoard" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_SENSOR_BOARD_TEMP XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTemperatureSensorBoard" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetTemperatureSensorBoard_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureSensorBoard" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_SENSOR_BOARD_TEMP XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTemperatureSensorBoard" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetTemperatureSensorBoard_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureSensorBoard" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_SENSOR_BOARD_TEMP XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTemperatureSensorBoard" "_Increment");
		return val;
	}
	 
	
	// Temperature element selector (TEC(Peltier), Fan). (XI_PRM_TEMP_ELEMENT_SEL)
	XI_TEMP_ELEMENT_SELECTOR xiAPIplus_Camera::GetTemperatureElementSelector()
	{
		int val=0;
		
		CheckCamHandle("GetTemperatureElementSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEMP_ELEMENT_SEL, &val);
		CheckResult(res,"GetTemperatureElementSelector");
		return (XI_TEMP_ELEMENT_SELECTOR)val;
	}
	
	XI_TEMP_ELEMENT_SELECTOR xiAPIplus_Camera::GetTemperatureElementSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetTemperatureElementSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEMP_ELEMENT_SEL XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTemperatureElementSelector" "_Maximum");
		return (XI_TEMP_ELEMENT_SELECTOR)val;
	}
	
	XI_TEMP_ELEMENT_SELECTOR xiAPIplus_Camera::GetTemperatureElementSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetTemperatureElementSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEMP_ELEMENT_SEL XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTemperatureElementSelector" "_Minimum");
		return (XI_TEMP_ELEMENT_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetTemperatureElementSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetTemperatureElementSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TEMP_ELEMENT_SEL XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTemperatureElementSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetTemperatureElementSelector(XI_TEMP_ELEMENT_SELECTOR TemperatureElementSelector)
	{
		
		CheckCamHandleInt("SetTemperatureElementSelector",(int)TemperatureElementSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_TEMP_ELEMENT_SEL, TemperatureElementSelector);
		CheckResult(res,"SetTemperatureElementSelector");
	}
	 
	
	// Temperature element value in percents of full control range (XI_PRM_TEMP_ELEMENT_VALUE)
	float xiAPIplus_Camera::GetTemperatureElementValue()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureElementValue");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_TEMP_ELEMENT_VALUE, &val);
		CheckResult(res,"GetTemperatureElementValue");
		return val;
	}

	float xiAPIplus_Camera::GetTemperatureElementValue_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureElementValue" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_TEMP_ELEMENT_VALUE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTemperatureElementValue" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetTemperatureElementValue_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureElementValue" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_TEMP_ELEMENT_VALUE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTemperatureElementValue" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetTemperatureElementValue_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetTemperatureElementValue" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_TEMP_ELEMENT_VALUE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTemperatureElementValue" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetTemperatureElementValue(float TemperatureElementValue)
	{
		
		CheckCamHandle("SetTemperatureElementValue");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_TEMP_ELEMENT_VALUE, TemperatureElementValue);
		CheckResult(res,"SetTemperatureElementValue");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Color Correction
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Mode of color management system. (XI_PRM_CMS)
	XI_CMS_MODE xiAPIplus_Camera::GetColorManagementMode()
	{
		int val=0;
		
		CheckCamHandle("GetColorManagementMode");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CMS, &val);
		CheckResult(res,"GetColorManagementMode");
		return (XI_CMS_MODE)val;
	}
	
	XI_CMS_MODE xiAPIplus_Camera::GetColorManagementMode_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetColorManagementMode" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CMS XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorManagementMode" "_Maximum");
		return (XI_CMS_MODE)val;
	}
	
	XI_CMS_MODE xiAPIplus_Camera::GetColorManagementMode_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetColorManagementMode" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CMS XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorManagementMode" "_Minimum");
		return (XI_CMS_MODE)val;
	}
	
	int xiAPIplus_Camera::GetColorManagementMode_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetColorManagementMode" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CMS XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorManagementMode" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorManagementMode(XI_CMS_MODE ColorManagementMode)
	{
		
		CheckCamHandleInt("SetColorManagementMode",(int)ColorManagementMode);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_CMS, ColorManagementMode);
		CheckResult(res,"SetColorManagementMode");
	}
	 
	
	// Intent of color management system. (XI_PRM_CMS_INTENT)
	XI_CMS_INTENT xiAPIplus_Camera::GetColorManagementIntent()
	{
		int val=0;
		
		CheckCamHandle("GetColorManagementIntent");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CMS_INTENT, &val);
		CheckResult(res,"GetColorManagementIntent");
		return (XI_CMS_INTENT)val;
	}
	
	XI_CMS_INTENT xiAPIplus_Camera::GetColorManagementIntent_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetColorManagementIntent" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CMS_INTENT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorManagementIntent" "_Maximum");
		return (XI_CMS_INTENT)val;
	}
	
	XI_CMS_INTENT xiAPIplus_Camera::GetColorManagementIntent_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetColorManagementIntent" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CMS_INTENT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorManagementIntent" "_Minimum");
		return (XI_CMS_INTENT)val;
	}
	
	int xiAPIplus_Camera::GetColorManagementIntent_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetColorManagementIntent" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CMS_INTENT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorManagementIntent" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorManagementIntent(XI_CMS_INTENT ColorManagementIntent)
	{
		
		CheckCamHandleInt("SetColorManagementIntent",(int)ColorManagementIntent);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_CMS_INTENT, ColorManagementIntent);
		CheckResult(res,"SetColorManagementIntent");
	}
	 
	
	// Enable applying of CMS profiles to xiGetImage (see XI_PRM_INPUT_CMS_PROFILE, XI_PRM_OUTPUT_CMS_PROFILE). (XI_PRM_APPLY_CMS)
	bool xiAPIplus_Camera::IsColorManagementApply()
	{
		int val=0;
		
		CheckCamHandle("IsColorManagementApply");
		
		xiGetParamInt(camera_handle, XI_PRM_APPLY_CMS, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableColorManagementApply()
	{
		
		CheckCamHandle("IsColorManagementApply");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_APPLY_CMS, XI_ON);
		CheckResult(res,"EnableColorManagementApply");
	}

	void xiAPIplus_Camera::DisableColorManagementApply()
	{
		
		CheckCamHandle("DisableColorManagementApply");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_APPLY_CMS, XI_OFF);
		CheckResult(res,"DisableColorManagementApply");
	}	
	 
	
	// Filename for input cms profile (e.g. input.icc) (XI_PRM_INPUT_CMS_PROFILE)
	void xiAPIplus_Camera::GetColorManagementInputProfile(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetColorManagementInputProfile");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_INPUT_CMS_PROFILE, buffer, buffer_length);
		CheckResult(res,"GetColorManagementInputProfile");
	}
	
	void xiAPIplus_Camera::SetColorManagementInputProfile(char* new_value)
	{
		
		CheckCamHandle("SetColorManagementInputProfile");
		
		XI_RETURN res=xiSetParamString(camera_handle, XI_PRM_INPUT_CMS_PROFILE, new_value, (DWORD)strlen(new_value));
		CheckResult(res,"SetColorManagementInputProfile");
	}
	 
	
	// Filename for output cms profile (e.g. input.icc) (XI_PRM_OUTPUT_CMS_PROFILE)
	void xiAPIplus_Camera::GetColorManagementOutputProfile(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetColorManagementOutputProfile");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_OUTPUT_CMS_PROFILE, buffer, buffer_length);
		CheckResult(res,"GetColorManagementOutputProfile");
	}
	
	void xiAPIplus_Camera::SetColorManagementOutputProfile(char* new_value)
	{
		
		CheckCamHandle("SetColorManagementOutputProfile");
		
		XI_RETURN res=xiSetParamString(camera_handle, XI_PRM_OUTPUT_CMS_PROFILE, new_value, (DWORD)strlen(new_value));
		CheckResult(res,"SetColorManagementOutputProfile");
	}
	 
	
	// Returns 1 for color cameras. (XI_PRM_IMAGE_IS_COLOR)
	bool xiAPIplus_Camera::IsSensorColor()
	{
		int val=0;
		
		CheckCamHandle("IsSensorColor");
		
		xiGetParamInt(camera_handle, XI_PRM_IMAGE_IS_COLOR, &val);
		return (val!=0);
	}
	 
	
	// Returns color filter array type of RAW data. (XI_PRM_COLOR_FILTER_ARRAY)
	XI_COLOR_FILTER_ARRAY xiAPIplus_Camera::GetSensorColorFilterArray()
	{
		int val=0;
		
		CheckCamHandle("GetSensorColorFilterArray");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COLOR_FILTER_ARRAY, &val);
		CheckResult(res,"GetSensorColorFilterArray");
		return (XI_COLOR_FILTER_ARRAY)val;
	}
	
	XI_COLOR_FILTER_ARRAY xiAPIplus_Camera::GetSensorColorFilterArray_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetSensorColorFilterArray" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COLOR_FILTER_ARRAY XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetSensorColorFilterArray" "_Maximum");
		return (XI_COLOR_FILTER_ARRAY)val;
	}
	
	XI_COLOR_FILTER_ARRAY xiAPIplus_Camera::GetSensorColorFilterArray_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetSensorColorFilterArray" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COLOR_FILTER_ARRAY XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetSensorColorFilterArray" "_Minimum");
		return (XI_COLOR_FILTER_ARRAY)val;
	}
	
	int xiAPIplus_Camera::GetSensorColorFilterArray_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetSensorColorFilterArray" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COLOR_FILTER_ARRAY XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetSensorColorFilterArray" "_Increment");
		return val;
	}
	 
	
	// Luminosity gamma (XI_PRM_GAMMAY)
	float xiAPIplus_Camera::GetGammaLuminosity()
	{
		float val=0;
		
		CheckCamHandle("GetGammaLuminosity");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_GAMMAY, &val);
		CheckResult(res,"GetGammaLuminosity");
		return val;
	}

	float xiAPIplus_Camera::GetGammaLuminosity_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetGammaLuminosity" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_GAMMAY XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetGammaLuminosity" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetGammaLuminosity_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetGammaLuminosity" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_GAMMAY XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetGammaLuminosity" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetGammaLuminosity_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetGammaLuminosity" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_GAMMAY XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetGammaLuminosity" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetGammaLuminosity(float GammaLuminosity)
	{
		
		CheckCamHandle("SetGammaLuminosity");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_GAMMAY, GammaLuminosity);
		CheckResult(res,"SetGammaLuminosity");
	}
	 
	
	// Chromaticity gamma (XI_PRM_GAMMAC)
	float xiAPIplus_Camera::GetGammaChromaticity()
	{
		float val=0;
		
		CheckCamHandle("GetGammaChromaticity");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_GAMMAC, &val);
		CheckResult(res,"GetGammaChromaticity");
		return val;
	}

	float xiAPIplus_Camera::GetGammaChromaticity_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetGammaChromaticity" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_GAMMAC XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetGammaChromaticity" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetGammaChromaticity_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetGammaChromaticity" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_GAMMAC XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetGammaChromaticity" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetGammaChromaticity_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetGammaChromaticity" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_GAMMAC XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetGammaChromaticity" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetGammaChromaticity(float GammaChromaticity)
	{
		
		CheckCamHandle("SetGammaChromaticity");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_GAMMAC, GammaChromaticity);
		CheckResult(res,"SetGammaChromaticity");
	}
	 
	
	// Sharpness strength (XI_PRM_SHARPNESS)
	float xiAPIplus_Camera::GetSharpness()
	{
		float val=0;
		
		CheckCamHandle("GetSharpness");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_SHARPNESS, &val);
		CheckResult(res,"GetSharpness");
		return val;
	}

	float xiAPIplus_Camera::GetSharpness_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetSharpness" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_SHARPNESS XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetSharpness" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetSharpness_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetSharpness" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_SHARPNESS XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetSharpness" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetSharpness_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetSharpness" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_SHARPNESS XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetSharpness" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetSharpness(float Sharpness)
	{
		
		CheckCamHandle("SetSharpness");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_SHARPNESS, Sharpness);
		CheckResult(res,"SetSharpness");
	}
	 
	
	// Color Correction Matrix element [0][0] (XI_PRM_CC_MATRIX_00)
	float xiAPIplus_Camera::GetColorCorrectionMatrix00()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix00");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_00, &val);
		CheckResult(res,"GetColorCorrectionMatrix00");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix00_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix00" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_00 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix00" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix00_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix00" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_00 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix00" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix00_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix00" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_00 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix00" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix00(float ColorCorrectionMatrix00)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix00");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_00, ColorCorrectionMatrix00);
		CheckResult(res,"SetColorCorrectionMatrix00");
	}
	 
	
	// Color Correction Matrix element [0][1] (XI_PRM_CC_MATRIX_01)
	float xiAPIplus_Camera::GetColorCorrectionMatrix01()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix01");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_01, &val);
		CheckResult(res,"GetColorCorrectionMatrix01");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix01_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix01" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_01 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix01" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix01_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix01" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_01 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix01" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix01_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix01" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_01 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix01" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix01(float ColorCorrectionMatrix01)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix01");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_01, ColorCorrectionMatrix01);
		CheckResult(res,"SetColorCorrectionMatrix01");
	}
	 
	
	// Color Correction Matrix element [0][2] (XI_PRM_CC_MATRIX_02)
	float xiAPIplus_Camera::GetColorCorrectionMatrix02()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix02");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_02, &val);
		CheckResult(res,"GetColorCorrectionMatrix02");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix02_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix02" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_02 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix02" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix02_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix02" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_02 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix02" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix02_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix02" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_02 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix02" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix02(float ColorCorrectionMatrix02)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix02");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_02, ColorCorrectionMatrix02);
		CheckResult(res,"SetColorCorrectionMatrix02");
	}
	 
	
	// Color Correction Matrix element [0][3] (XI_PRM_CC_MATRIX_03)
	float xiAPIplus_Camera::GetColorCorrectionMatrix03()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix03");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_03, &val);
		CheckResult(res,"GetColorCorrectionMatrix03");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix03_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix03" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_03 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix03" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix03_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix03" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_03 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix03" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix03_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix03" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_03 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix03" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix03(float ColorCorrectionMatrix03)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix03");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_03, ColorCorrectionMatrix03);
		CheckResult(res,"SetColorCorrectionMatrix03");
	}
	 
	
	// Color Correction Matrix element [1][0] (XI_PRM_CC_MATRIX_10)
	float xiAPIplus_Camera::GetColorCorrectionMatrix10()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix10");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_10, &val);
		CheckResult(res,"GetColorCorrectionMatrix10");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix10_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix10" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_10 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix10" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix10_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix10" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_10 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix10" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix10_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix10" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_10 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix10" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix10(float ColorCorrectionMatrix10)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix10");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_10, ColorCorrectionMatrix10);
		CheckResult(res,"SetColorCorrectionMatrix10");
	}
	 
	
	// Color Correction Matrix element [1][1] (XI_PRM_CC_MATRIX_11)
	float xiAPIplus_Camera::GetColorCorrectionMatrix11()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix11");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_11, &val);
		CheckResult(res,"GetColorCorrectionMatrix11");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix11_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix11" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_11 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix11" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix11_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix11" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_11 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix11" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix11_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix11" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_11 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix11" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix11(float ColorCorrectionMatrix11)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix11");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_11, ColorCorrectionMatrix11);
		CheckResult(res,"SetColorCorrectionMatrix11");
	}
	 
	
	// Color Correction Matrix element [1][2] (XI_PRM_CC_MATRIX_12)
	float xiAPIplus_Camera::GetColorCorrectionMatrix12()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix12");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_12, &val);
		CheckResult(res,"GetColorCorrectionMatrix12");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix12_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix12" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_12 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix12" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix12_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix12" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_12 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix12" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix12_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix12" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_12 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix12" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix12(float ColorCorrectionMatrix12)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix12");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_12, ColorCorrectionMatrix12);
		CheckResult(res,"SetColorCorrectionMatrix12");
	}
	 
	
	// Color Correction Matrix element [1][3] (XI_PRM_CC_MATRIX_13)
	float xiAPIplus_Camera::GetColorCorrectionMatrix13()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix13");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_13, &val);
		CheckResult(res,"GetColorCorrectionMatrix13");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix13_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix13" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_13 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix13" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix13_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix13" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_13 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix13" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix13_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix13" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_13 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix13" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix13(float ColorCorrectionMatrix13)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix13");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_13, ColorCorrectionMatrix13);
		CheckResult(res,"SetColorCorrectionMatrix13");
	}
	 
	
	// Color Correction Matrix element [2][0] (XI_PRM_CC_MATRIX_20)
	float xiAPIplus_Camera::GetColorCorrectionMatrix20()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix20");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_20, &val);
		CheckResult(res,"GetColorCorrectionMatrix20");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix20_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix20" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_20 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix20" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix20_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix20" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_20 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix20" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix20_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix20" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_20 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix20" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix20(float ColorCorrectionMatrix20)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix20");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_20, ColorCorrectionMatrix20);
		CheckResult(res,"SetColorCorrectionMatrix20");
	}
	 
	
	// Color Correction Matrix element [2][1] (XI_PRM_CC_MATRIX_21)
	float xiAPIplus_Camera::GetColorCorrectionMatrix21()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix21");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_21, &val);
		CheckResult(res,"GetColorCorrectionMatrix21");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix21_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix21" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_21 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix21" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix21_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix21" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_21 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix21" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix21_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix21" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_21 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix21" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix21(float ColorCorrectionMatrix21)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix21");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_21, ColorCorrectionMatrix21);
		CheckResult(res,"SetColorCorrectionMatrix21");
	}
	 
	
	// Color Correction Matrix element [2][2] (XI_PRM_CC_MATRIX_22)
	float xiAPIplus_Camera::GetColorCorrectionMatrix22()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix22");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_22, &val);
		CheckResult(res,"GetColorCorrectionMatrix22");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix22_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix22" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_22 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix22" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix22_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix22" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_22 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix22" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix22_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix22" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_22 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix22" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix22(float ColorCorrectionMatrix22)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix22");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_22, ColorCorrectionMatrix22);
		CheckResult(res,"SetColorCorrectionMatrix22");
	}
	 
	
	// Color Correction Matrix element [2][3] (XI_PRM_CC_MATRIX_23)
	float xiAPIplus_Camera::GetColorCorrectionMatrix23()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix23");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_23, &val);
		CheckResult(res,"GetColorCorrectionMatrix23");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix23_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix23" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_23 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix23" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix23_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix23" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_23 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix23" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix23_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix23" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_23 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix23" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix23(float ColorCorrectionMatrix23)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix23");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_23, ColorCorrectionMatrix23);
		CheckResult(res,"SetColorCorrectionMatrix23");
	}
	 
	
	// Color Correction Matrix element [3][0] (XI_PRM_CC_MATRIX_30)
	float xiAPIplus_Camera::GetColorCorrectionMatrix30()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix30");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_30, &val);
		CheckResult(res,"GetColorCorrectionMatrix30");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix30_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix30" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_30 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix30" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix30_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix30" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_30 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix30" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix30_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix30" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_30 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix30" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix30(float ColorCorrectionMatrix30)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix30");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_30, ColorCorrectionMatrix30);
		CheckResult(res,"SetColorCorrectionMatrix30");
	}
	 
	
	// Color Correction Matrix element [3][1] (XI_PRM_CC_MATRIX_31)
	float xiAPIplus_Camera::GetColorCorrectionMatrix31()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix31");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_31, &val);
		CheckResult(res,"GetColorCorrectionMatrix31");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix31_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix31" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_31 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix31" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix31_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix31" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_31 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix31" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix31_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix31" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_31 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix31" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix31(float ColorCorrectionMatrix31)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix31");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_31, ColorCorrectionMatrix31);
		CheckResult(res,"SetColorCorrectionMatrix31");
	}
	 
	
	// Color Correction Matrix element [3][2] (XI_PRM_CC_MATRIX_32)
	float xiAPIplus_Camera::GetColorCorrectionMatrix32()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix32");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_32, &val);
		CheckResult(res,"GetColorCorrectionMatrix32");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix32_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix32" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_32 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix32" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix32_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix32" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_32 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix32" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix32_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix32" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_32 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix32" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix32(float ColorCorrectionMatrix32)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix32");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_32, ColorCorrectionMatrix32);
		CheckResult(res,"SetColorCorrectionMatrix32");
	}
	 
	
	// Color Correction Matrix element [3][3] (XI_PRM_CC_MATRIX_33)
	float xiAPIplus_Camera::GetColorCorrectionMatrix33()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix33");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_33, &val);
		CheckResult(res,"GetColorCorrectionMatrix33");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix33_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix33" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_33 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColorCorrectionMatrix33" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix33_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix33" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_33 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColorCorrectionMatrix33" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetColorCorrectionMatrix33_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetColorCorrectionMatrix33" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_CC_MATRIX_33 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColorCorrectionMatrix33" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColorCorrectionMatrix33(float ColorCorrectionMatrix33)
	{
		
		CheckCamHandle("SetColorCorrectionMatrix33");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_CC_MATRIX_33, ColorCorrectionMatrix33);
		CheckResult(res,"SetColorCorrectionMatrix33");
	}
	 
	
	// Set default Color Correction Matrix (XI_PRM_DEFAULT_CC_MATRIX)
	void xiAPIplus_Camera::SetColorCorrectionMatrixDefault(int ColorCorrectionMatrixDefault)
	{
		
		CheckCamHandleInt("SetColorCorrectionMatrixDefault",ColorCorrectionMatrixDefault);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DEFAULT_CC_MATRIX, ColorCorrectionMatrixDefault);
		CheckResult(res,"SetColorCorrectionMatrixDefault");
	}
	 
	
	// Normalize color correction matrix (XI_PRM_CC_MATRIX_NORM)
	bool xiAPIplus_Camera::IsColorCorrectionMatrixNorm()
	{
		int val=0;
		
		CheckCamHandle("IsColorCorrectionMatrixNorm");
		
		xiGetParamInt(camera_handle, XI_PRM_CC_MATRIX_NORM, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableColorCorrectionMatrixNorm()
	{
		
		CheckCamHandle("IsColorCorrectionMatrixNorm");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_CC_MATRIX_NORM, XI_ON);
		CheckResult(res,"EnableColorCorrectionMatrixNorm");
	}

	void xiAPIplus_Camera::DisableColorCorrectionMatrixNorm()
	{
		
		CheckCamHandle("DisableColorCorrectionMatrixNorm");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_CC_MATRIX_NORM, XI_OFF);
		CheckResult(res,"DisableColorCorrectionMatrixNorm");
	}	
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Device IO
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Defines source of trigger. (XI_PRM_TRG_SOURCE)
	XI_TRG_SOURCE xiAPIplus_Camera::GetTriggerSource()
	{
		int val=0;
		
		CheckCamHandle("GetTriggerSource");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_SOURCE, &val);
		CheckResult(res,"GetTriggerSource");
		return (XI_TRG_SOURCE)val;
	}
	
	XI_TRG_SOURCE xiAPIplus_Camera::GetTriggerSource_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetTriggerSource" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_SOURCE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTriggerSource" "_Maximum");
		return (XI_TRG_SOURCE)val;
	}
	
	XI_TRG_SOURCE xiAPIplus_Camera::GetTriggerSource_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetTriggerSource" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_SOURCE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTriggerSource" "_Minimum");
		return (XI_TRG_SOURCE)val;
	}
	
	int xiAPIplus_Camera::GetTriggerSource_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetTriggerSource" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_SOURCE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTriggerSource" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetTriggerSource(XI_TRG_SOURCE TriggerSource)
	{
		
		CheckCamHandleInt("SetTriggerSource",(int)TriggerSource);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_TRG_SOURCE, TriggerSource);
		CheckResult(res,"SetTriggerSource");
	}
	 
	
	// Generates an internal trigger. XI_PRM_TRG_SOURCE must be set to TRG_SOFTWARE. (XI_PRM_TRG_SOFTWARE)
	void xiAPIplus_Camera::SetTriggerSoftware(int TriggerSoftware)
	{
		
		CheckCamHandleInt("SetTriggerSoftware",TriggerSoftware);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_TRG_SOFTWARE, TriggerSoftware);
		CheckResult(res,"SetTriggerSoftware");
	}
	 
	
	// Selects the type of trigger. (XI_PRM_TRG_SELECTOR)
	XI_TRG_SELECTOR xiAPIplus_Camera::GetTriggerSelector()
	{
		int val=0;
		
		CheckCamHandle("GetTriggerSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_SELECTOR, &val);
		CheckResult(res,"GetTriggerSelector");
		return (XI_TRG_SELECTOR)val;
	}
	
	XI_TRG_SELECTOR xiAPIplus_Camera::GetTriggerSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetTriggerSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTriggerSelector" "_Maximum");
		return (XI_TRG_SELECTOR)val;
	}
	
	XI_TRG_SELECTOR xiAPIplus_Camera::GetTriggerSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetTriggerSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTriggerSelector" "_Minimum");
		return (XI_TRG_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetTriggerSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetTriggerSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTriggerSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetTriggerSelector(XI_TRG_SELECTOR TriggerSelector)
	{
		
		CheckCamHandleInt("SetTriggerSelector",(int)TriggerSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_TRG_SELECTOR, TriggerSelector);
		CheckResult(res,"SetTriggerSelector");
	}
	 
	
	// The mode of Trigger Overlap. This influences of trigger acception/rejection policy (XI_PRM_TRG_OVERLAP)
	XI_TRG_OVERLAP xiAPIplus_Camera::GetTriggerOverlap()
	{
		int val=0;
		
		CheckCamHandle("GetTriggerOverlap");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_OVERLAP, &val);
		CheckResult(res,"GetTriggerOverlap");
		return (XI_TRG_OVERLAP)val;
	}
	
	XI_TRG_OVERLAP xiAPIplus_Camera::GetTriggerOverlap_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetTriggerOverlap" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_OVERLAP XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTriggerOverlap" "_Maximum");
		return (XI_TRG_OVERLAP)val;
	}
	
	XI_TRG_OVERLAP xiAPIplus_Camera::GetTriggerOverlap_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetTriggerOverlap" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_OVERLAP XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTriggerOverlap" "_Minimum");
		return (XI_TRG_OVERLAP)val;
	}
	
	int xiAPIplus_Camera::GetTriggerOverlap_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetTriggerOverlap" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_OVERLAP XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTriggerOverlap" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetTriggerOverlap(XI_TRG_OVERLAP TriggerOverlap)
	{
		
		CheckCamHandleInt("SetTriggerOverlap",(int)TriggerOverlap);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_TRG_OVERLAP, TriggerOverlap);
		CheckResult(res,"SetTriggerOverlap");
	}
	 
	
	// Sets number of frames acquired by burst. This burst is used only if trigger is set to FrameBurstStart (XI_PRM_ACQ_FRAME_BURST_COUNT)
	// integer type
	int xiAPIplus_Camera::GetAcquisitionFrameBurstCount()
	{
		CheckCamHandle("GetAcquisitionFrameBurstCount");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_FRAME_BURST_COUNT, &val);
		CheckResult(res,"GetAcquisitionFrameBurstCount");
		return val;	
	}
	int xiAPIplus_Camera::GetAcquisitionFrameBurstCount_Maximum()
	{		
		CheckCamHandle("GetAcquisitionFrameBurstCount" "_Maximum");
		int val=0;
		CheckCamHandle("GetAcquisitionFrameBurstCount");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_FRAME_BURST_COUNT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAcquisitionFrameBurstCount" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetAcquisitionFrameBurstCount_Minimum()
	{
		CheckCamHandle("GetAcquisitionFrameBurstCount" "_Minimum");
		int val=0;
		CheckCamHandle("GetAcquisitionFrameBurstCount");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_FRAME_BURST_COUNT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAcquisitionFrameBurstCount" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetAcquisitionFrameBurstCount_Increment()
	{
		CheckCamHandle("GetAcquisitionFrameBurstCount" "_Increment");
		int val=0;
		CheckCamHandle("GetAcquisitionFrameBurstCount");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_FRAME_BURST_COUNT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAcquisitionFrameBurstCount" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetAcquisitionFrameBurstCount(int AcquisitionFrameBurstCount)
	{
		
		CheckCamHandleInt("SetAcquisitionFrameBurstCount",AcquisitionFrameBurstCount);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_ACQ_FRAME_BURST_COUNT, AcquisitionFrameBurstCount);
		CheckResult(res,"SetAcquisitionFrameBurstCount");
	}
	 
	
	// Current value of the device timestamp counter (XI_PRM_TIMESTAMP)
	// integer type
	uint64_t xiAPIplus_Camera::GetTimestamp()
	{
		CheckCamHandle("GetTimestamp");
		uint64_t val=0;
		DWORD size = sizeof(val);
		XI_PRM_TYPE type = xiTypeInteger64;		
		XI_RETURN res=xiGetParam(camera_handle, XI_PRM_TIMESTAMP, &val, &size, &type);
		CheckResult(res,"GetTimestamp");
		return val;	
	}
	uint64_t xiAPIplus_Camera::GetTimestamp_Maximum()
	{		
		CheckCamHandle("GetTimestamp" "_Maximum");
		uint64_t val=0;
		DWORD size = sizeof(val);
		XI_PRM_TYPE type = xiTypeInteger64;
		XI_RETURN res=xiGetParam(camera_handle, XI_PRM_TIMESTAMP XI_PRM_INFO_MAX, &val, &size, &type);
		CheckResult(res,"GetTimestamp" "_Maximum");
		return val;
	}
	
	uint64_t xiAPIplus_Camera::GetTimestamp_Minimum()
	{
		CheckCamHandle("GetTimestamp" "_Minimum");
		uint64_t val=0;
		DWORD size = sizeof(val);
		XI_PRM_TYPE type = xiTypeInteger64;
		XI_RETURN res=xiGetParam(camera_handle, XI_PRM_TIMESTAMP XI_PRM_INFO_MIN, &val, &size, &type);
		CheckResult(res,"GetTimestamp" "_Minimum");
		return val;
	}

	uint64_t xiAPIplus_Camera::GetTimestamp_Increment()
	{
		CheckCamHandle("GetTimestamp" "_Increment");
		uint64_t val=0;
		DWORD size = sizeof(val);
		XI_PRM_TYPE type = xiTypeInteger64;
		XI_RETURN res=xiGetParam(camera_handle, XI_PRM_TIMESTAMP XI_PRM_INFO_INCREMENT, &val, &size, &type);
		CheckResult(res,"GetTimestamp" "_Increment");
		return val;		
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: GPIO Setup
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Selects GPI (XI_PRM_GPI_SELECTOR)
	XI_GPI_SELECTOR xiAPIplus_Camera::GetGPISelector()
	{
		int val=0;
		
		CheckCamHandle("GetGPISelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_SELECTOR, &val);
		CheckResult(res,"GetGPISelector");
		return (XI_GPI_SELECTOR)val;
	}
	
	XI_GPI_SELECTOR xiAPIplus_Camera::GetGPISelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetGPISelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetGPISelector" "_Maximum");
		return (XI_GPI_SELECTOR)val;
	}
	
	XI_GPI_SELECTOR xiAPIplus_Camera::GetGPISelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetGPISelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetGPISelector" "_Minimum");
		return (XI_GPI_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetGPISelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetGPISelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetGPISelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetGPISelector(XI_GPI_SELECTOR GPISelector)
	{
		
		CheckCamHandleInt("SetGPISelector",(int)GPISelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_GPI_SELECTOR, GPISelector);
		CheckResult(res,"SetGPISelector");
	}
	 
	
	// Defines GPI functionality (XI_PRM_GPI_MODE)
	XI_GPI_MODE xiAPIplus_Camera::GetGPIMode()
	{
		int val=0;
		
		CheckCamHandle("GetGPIMode");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_MODE, &val);
		CheckResult(res,"GetGPIMode");
		return (XI_GPI_MODE)val;
	}
	
	XI_GPI_MODE xiAPIplus_Camera::GetGPIMode_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetGPIMode" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_MODE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetGPIMode" "_Maximum");
		return (XI_GPI_MODE)val;
	}
	
	XI_GPI_MODE xiAPIplus_Camera::GetGPIMode_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetGPIMode" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_MODE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetGPIMode" "_Minimum");
		return (XI_GPI_MODE)val;
	}
	
	int xiAPIplus_Camera::GetGPIMode_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetGPIMode" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_MODE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetGPIMode" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetGPIMode(XI_GPI_MODE GPIMode)
	{
		
		CheckCamHandleInt("SetGPIMode",(int)GPIMode);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_GPI_MODE, GPIMode);
		CheckResult(res,"SetGPIMode");
	}
	 
	
	// GPI level (XI_PRM_GPI_LEVEL)
	// integer type
	int xiAPIplus_Camera::GetGPILevel()
	{
		CheckCamHandle("GetGPILevel");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_LEVEL, &val);
		CheckResult(res,"GetGPILevel");
		return val;	
	}
	int xiAPIplus_Camera::GetGPILevel_Maximum()
	{		
		CheckCamHandle("GetGPILevel" "_Maximum");
		int val=0;
		CheckCamHandle("GetGPILevel");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_LEVEL XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetGPILevel" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetGPILevel_Minimum()
	{
		CheckCamHandle("GetGPILevel" "_Minimum");
		int val=0;
		CheckCamHandle("GetGPILevel");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_LEVEL XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetGPILevel" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetGPILevel_Increment()
	{
		CheckCamHandle("GetGPILevel" "_Increment");
		int val=0;
		CheckCamHandle("GetGPILevel");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_LEVEL XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetGPILevel" "_Increment");
		return val;		
	}
	 
	
	// GPI Level at image exposure start (XI_PRM_GPI_LEVEL_AT_IMAGE_EXP_START)
	// integer type
	int xiAPIplus_Camera::GetGPILevelAtImageExpStart()
	{
		CheckCamHandle("GetGPILevelAtImageExpStart");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_LEVEL_AT_IMAGE_EXP_START, &val);
		CheckResult(res,"GetGPILevelAtImageExpStart");
		return val;	
	}
	int xiAPIplus_Camera::GetGPILevelAtImageExpStart_Maximum()
	{		
		CheckCamHandle("GetGPILevelAtImageExpStart" "_Maximum");
		int val=0;
		CheckCamHandle("GetGPILevelAtImageExpStart");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_LEVEL_AT_IMAGE_EXP_START XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetGPILevelAtImageExpStart" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetGPILevelAtImageExpStart_Minimum()
	{
		CheckCamHandle("GetGPILevelAtImageExpStart" "_Minimum");
		int val=0;
		CheckCamHandle("GetGPILevelAtImageExpStart");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_LEVEL_AT_IMAGE_EXP_START XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetGPILevelAtImageExpStart" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetGPILevelAtImageExpStart_Increment()
	{
		CheckCamHandle("GetGPILevelAtImageExpStart" "_Increment");
		int val=0;
		CheckCamHandle("GetGPILevelAtImageExpStart");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_LEVEL_AT_IMAGE_EXP_START XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetGPILevelAtImageExpStart" "_Increment");
		return val;		
	}
	 
	
	// GPI Level at image exposure end (XI_PRM_GPI_LEVEL_AT_IMAGE_EXP_END)
	// integer type
	int xiAPIplus_Camera::GetGPILevelAtImageExpEnd()
	{
		CheckCamHandle("GetGPILevelAtImageExpEnd");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_LEVEL_AT_IMAGE_EXP_END, &val);
		CheckResult(res,"GetGPILevelAtImageExpEnd");
		return val;	
	}
	int xiAPIplus_Camera::GetGPILevelAtImageExpEnd_Maximum()
	{		
		CheckCamHandle("GetGPILevelAtImageExpEnd" "_Maximum");
		int val=0;
		CheckCamHandle("GetGPILevelAtImageExpEnd");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_LEVEL_AT_IMAGE_EXP_END XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetGPILevelAtImageExpEnd" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetGPILevelAtImageExpEnd_Minimum()
	{
		CheckCamHandle("GetGPILevelAtImageExpEnd" "_Minimum");
		int val=0;
		CheckCamHandle("GetGPILevelAtImageExpEnd");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_LEVEL_AT_IMAGE_EXP_END XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetGPILevelAtImageExpEnd" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetGPILevelAtImageExpEnd_Increment()
	{
		CheckCamHandle("GetGPILevelAtImageExpEnd" "_Increment");
		int val=0;
		CheckCamHandle("GetGPILevelAtImageExpEnd");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPI_LEVEL_AT_IMAGE_EXP_END XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetGPILevelAtImageExpEnd" "_Increment");
		return val;		
	}
	 
	
	// Selects GPO (XI_PRM_GPO_SELECTOR)
	XI_GPO_SELECTOR xiAPIplus_Camera::GetGPOSelector()
	{
		int val=0;
		
		CheckCamHandle("GetGPOSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPO_SELECTOR, &val);
		CheckResult(res,"GetGPOSelector");
		return (XI_GPO_SELECTOR)val;
	}
	
	XI_GPO_SELECTOR xiAPIplus_Camera::GetGPOSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetGPOSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPO_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetGPOSelector" "_Maximum");
		return (XI_GPO_SELECTOR)val;
	}
	
	XI_GPO_SELECTOR xiAPIplus_Camera::GetGPOSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetGPOSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPO_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetGPOSelector" "_Minimum");
		return (XI_GPO_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetGPOSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetGPOSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPO_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetGPOSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetGPOSelector(XI_GPO_SELECTOR GPOSelector)
	{
		
		CheckCamHandleInt("SetGPOSelector",(int)GPOSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_GPO_SELECTOR, GPOSelector);
		CheckResult(res,"SetGPOSelector");
	}
	 
	
	// Defines GPO functionality (XI_PRM_GPO_MODE)
	XI_GPO_MODE xiAPIplus_Camera::GetGPOMode()
	{
		int val=0;
		
		CheckCamHandle("GetGPOMode");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPO_MODE, &val);
		CheckResult(res,"GetGPOMode");
		return (XI_GPO_MODE)val;
	}
	
	XI_GPO_MODE xiAPIplus_Camera::GetGPOMode_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetGPOMode" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPO_MODE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetGPOMode" "_Maximum");
		return (XI_GPO_MODE)val;
	}
	
	XI_GPO_MODE xiAPIplus_Camera::GetGPOMode_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetGPOMode" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPO_MODE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetGPOMode" "_Minimum");
		return (XI_GPO_MODE)val;
	}
	
	int xiAPIplus_Camera::GetGPOMode_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetGPOMode" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_GPO_MODE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetGPOMode" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetGPOMode(XI_GPO_MODE GPOMode)
	{
		
		CheckCamHandleInt("SetGPOMode",(int)GPOMode);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_GPO_MODE, GPOMode);
		CheckResult(res,"SetGPOMode");
	}
	 
	
	// Selects LED (XI_PRM_LED_SELECTOR)
	XI_LED_SELECTOR xiAPIplus_Camera::GetLEDSelector()
	{
		int val=0;
		
		CheckCamHandle("GetLEDSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LED_SELECTOR, &val);
		CheckResult(res,"GetLEDSelector");
		return (XI_LED_SELECTOR)val;
	}
	
	XI_LED_SELECTOR xiAPIplus_Camera::GetLEDSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetLEDSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LED_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetLEDSelector" "_Maximum");
		return (XI_LED_SELECTOR)val;
	}
	
	XI_LED_SELECTOR xiAPIplus_Camera::GetLEDSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetLEDSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LED_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetLEDSelector" "_Minimum");
		return (XI_LED_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetLEDSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetLEDSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LED_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetLEDSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetLEDSelector(XI_LED_SELECTOR LEDSelector)
	{
		
		CheckCamHandleInt("SetLEDSelector",(int)LEDSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_LED_SELECTOR, LEDSelector);
		CheckResult(res,"SetLEDSelector");
	}
	 
	
	// Defines LED functionality (XI_PRM_LED_MODE)
	XI_LED_MODE xiAPIplus_Camera::GetLEDMode()
	{
		int val=0;
		
		CheckCamHandle("GetLEDMode");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LED_MODE, &val);
		CheckResult(res,"GetLEDMode");
		return (XI_LED_MODE)val;
	}
	
	XI_LED_MODE xiAPIplus_Camera::GetLEDMode_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetLEDMode" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LED_MODE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetLEDMode" "_Maximum");
		return (XI_LED_MODE)val;
	}
	
	XI_LED_MODE xiAPIplus_Camera::GetLEDMode_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetLEDMode" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LED_MODE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetLEDMode" "_Minimum");
		return (XI_LED_MODE)val;
	}
	
	int xiAPIplus_Camera::GetLEDMode_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetLEDMode" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LED_MODE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetLEDMode" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetLEDMode(XI_LED_MODE LEDMode)
	{
		
		CheckCamHandleInt("SetLEDMode",(int)LEDMode);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_LED_MODE, LEDMode);
		CheckResult(res,"SetLEDMode");
	}
	 
	
	// Enable/Disable debounce to selected GPI (XI_PRM_DEBOUNCE_EN)
	bool xiAPIplus_Camera::IsGPIDebounce()
	{
		int val=0;
		
		CheckCamHandle("IsGPIDebounce");
		
		xiGetParamInt(camera_handle, XI_PRM_DEBOUNCE_EN, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableGPIDebounce()
	{
		
		CheckCamHandle("IsGPIDebounce");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DEBOUNCE_EN, XI_ON);
		CheckResult(res,"EnableGPIDebounce");
	}

	void xiAPIplus_Camera::DisableGPIDebounce()
	{
		
		CheckCamHandle("DisableGPIDebounce");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DEBOUNCE_EN, XI_OFF);
		CheckResult(res,"DisableGPIDebounce");
	}	
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Debounce Setup
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Debounce time (x * 10us) (XI_PRM_DEBOUNCE_T0)
	// integer type
	int xiAPIplus_Camera::GetGPIDebounceFallingEdge()
	{
		CheckCamHandle("GetGPIDebounceFallingEdge");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBOUNCE_T0, &val);
		CheckResult(res,"GetGPIDebounceFallingEdge");
		return val;	
	}
	int xiAPIplus_Camera::GetGPIDebounceFallingEdge_Maximum()
	{		
		CheckCamHandle("GetGPIDebounceFallingEdge" "_Maximum");
		int val=0;
		CheckCamHandle("GetGPIDebounceFallingEdge");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBOUNCE_T0 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetGPIDebounceFallingEdge" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetGPIDebounceFallingEdge_Minimum()
	{
		CheckCamHandle("GetGPIDebounceFallingEdge" "_Minimum");
		int val=0;
		CheckCamHandle("GetGPIDebounceFallingEdge");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBOUNCE_T0 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetGPIDebounceFallingEdge" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetGPIDebounceFallingEdge_Increment()
	{
		CheckCamHandle("GetGPIDebounceFallingEdge" "_Increment");
		int val=0;
		CheckCamHandle("GetGPIDebounceFallingEdge");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBOUNCE_T0 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetGPIDebounceFallingEdge" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetGPIDebounceFallingEdge(int GPIDebounceFallingEdge)
	{
		
		CheckCamHandleInt("SetGPIDebounceFallingEdge",GPIDebounceFallingEdge);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DEBOUNCE_T0, GPIDebounceFallingEdge);
		CheckResult(res,"SetGPIDebounceFallingEdge");
	}
	 
	
	// Debounce time (x * 10us) (XI_PRM_DEBOUNCE_T1)
	// integer type
	int xiAPIplus_Camera::GetGPIDebounceRisingEdge()
	{
		CheckCamHandle("GetGPIDebounceRisingEdge");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBOUNCE_T1, &val);
		CheckResult(res,"GetGPIDebounceRisingEdge");
		return val;	
	}
	int xiAPIplus_Camera::GetGPIDebounceRisingEdge_Maximum()
	{		
		CheckCamHandle("GetGPIDebounceRisingEdge" "_Maximum");
		int val=0;
		CheckCamHandle("GetGPIDebounceRisingEdge");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBOUNCE_T1 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetGPIDebounceRisingEdge" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetGPIDebounceRisingEdge_Minimum()
	{
		CheckCamHandle("GetGPIDebounceRisingEdge" "_Minimum");
		int val=0;
		CheckCamHandle("GetGPIDebounceRisingEdge");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBOUNCE_T1 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetGPIDebounceRisingEdge" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetGPIDebounceRisingEdge_Increment()
	{
		CheckCamHandle("GetGPIDebounceRisingEdge" "_Increment");
		int val=0;
		CheckCamHandle("GetGPIDebounceRisingEdge");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBOUNCE_T1 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetGPIDebounceRisingEdge" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetGPIDebounceRisingEdge(int GPIDebounceRisingEdge)
	{
		
		CheckCamHandleInt("SetGPIDebounceRisingEdge",GPIDebounceRisingEdge);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DEBOUNCE_T1, GPIDebounceRisingEdge);
		CheckResult(res,"SetGPIDebounceRisingEdge");
	}
	 
	
	// Debounce polarity (pol = 1 t0 - falling edge, t1 - rising edge) (XI_PRM_DEBOUNCE_POL)
	// integer type
	int xiAPIplus_Camera::GetGPIDebouncePolarity()
	{
		CheckCamHandle("GetGPIDebouncePolarity");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBOUNCE_POL, &val);
		CheckResult(res,"GetGPIDebouncePolarity");
		return val;	
	}
	int xiAPIplus_Camera::GetGPIDebouncePolarity_Maximum()
	{		
		CheckCamHandle("GetGPIDebouncePolarity" "_Maximum");
		int val=0;
		CheckCamHandle("GetGPIDebouncePolarity");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBOUNCE_POL XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetGPIDebouncePolarity" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetGPIDebouncePolarity_Minimum()
	{
		CheckCamHandle("GetGPIDebouncePolarity" "_Minimum");
		int val=0;
		CheckCamHandle("GetGPIDebouncePolarity");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBOUNCE_POL XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetGPIDebouncePolarity" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetGPIDebouncePolarity_Increment()
	{
		CheckCamHandle("GetGPIDebouncePolarity" "_Increment");
		int val=0;
		CheckCamHandle("GetGPIDebouncePolarity");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBOUNCE_POL XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetGPIDebouncePolarity" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetGPIDebouncePolarity(int GPIDebouncePolarity)
	{
		
		CheckCamHandleInt("SetGPIDebouncePolarity",GPIDebouncePolarity);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DEBOUNCE_POL, GPIDebouncePolarity);
		CheckResult(res,"SetGPIDebouncePolarity");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Lens Control
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Status of lens control interface. This shall be set to XI_ON before any Lens operations. (XI_PRM_LENS_MODE)
	bool xiAPIplus_Camera::IsLensMode()
	{
		int val=0;
		
		CheckCamHandle("IsLensMode");
		
		xiGetParamInt(camera_handle, XI_PRM_LENS_MODE, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableLensMode()
	{
		
		CheckCamHandle("IsLensMode");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_LENS_MODE, XI_ON);
		CheckResult(res,"EnableLensMode");
	}

	void xiAPIplus_Camera::DisableLensMode()
	{
		
		CheckCamHandle("DisableLensMode");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_LENS_MODE, XI_OFF);
		CheckResult(res,"DisableLensMode");
	}	
	 
	
	// Current lens aperture value in stops. Examples: 2.8, 4, 5.6, 8, 11 (XI_PRM_LENS_APERTURE_VALUE)
	float xiAPIplus_Camera::GetLensApertureValue()
	{
		float val=0;
		
		CheckCamHandle("GetLensApertureValue");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_LENS_APERTURE_VALUE, &val);
		CheckResult(res,"GetLensApertureValue");
		return val;
	}

	float xiAPIplus_Camera::GetLensApertureValue_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetLensApertureValue" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_LENS_APERTURE_VALUE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetLensApertureValue" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetLensApertureValue_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetLensApertureValue" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_LENS_APERTURE_VALUE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetLensApertureValue" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetLensApertureValue_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetLensApertureValue" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_LENS_APERTURE_VALUE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetLensApertureValue" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetLensApertureValue(float LensApertureValue)
	{
		
		CheckCamHandle("SetLensApertureValue");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_LENS_APERTURE_VALUE, LensApertureValue);
		CheckResult(res,"SetLensApertureValue");
	}
	 
	
	// Current aperture index as reported by lens. (XI_PRM_LENS_APERTURE_INDEX)
	// integer type
	int xiAPIplus_Camera::GetLensApertureIndex()
	{
		CheckCamHandle("GetLensApertureIndex");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LENS_APERTURE_INDEX, &val);
		CheckResult(res,"GetLensApertureIndex");
		return val;	
	}
	int xiAPIplus_Camera::GetLensApertureIndex_Maximum()
	{		
		CheckCamHandle("GetLensApertureIndex" "_Maximum");
		int val=0;
		CheckCamHandle("GetLensApertureIndex");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LENS_APERTURE_INDEX XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetLensApertureIndex" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetLensApertureIndex_Minimum()
	{
		CheckCamHandle("GetLensApertureIndex" "_Minimum");
		int val=0;
		CheckCamHandle("GetLensApertureIndex");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LENS_APERTURE_INDEX XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetLensApertureIndex" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetLensApertureIndex_Increment()
	{
		CheckCamHandle("GetLensApertureIndex" "_Increment");
		int val=0;
		CheckCamHandle("GetLensApertureIndex");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LENS_APERTURE_INDEX XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetLensApertureIndex" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetLensApertureIndex(int LensApertureIndex)
	{
		
		CheckCamHandleInt("SetLensApertureIndex",LensApertureIndex);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_LENS_APERTURE_INDEX, LensApertureIndex);
		CheckResult(res,"SetLensApertureIndex");
	}
	 
	
	// Lens current focus movement value to be used by XI_PRM_LENS_FOCUS_MOVE in motor steps. (XI_PRM_LENS_FOCUS_MOVEMENT_VALUE)
	// integer type
	int xiAPIplus_Camera::GetLensFocusMovementValue()
	{
		CheckCamHandle("GetLensFocusMovementValue");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LENS_FOCUS_MOVEMENT_VALUE, &val);
		CheckResult(res,"GetLensFocusMovementValue");
		return val;	
	}
	int xiAPIplus_Camera::GetLensFocusMovementValue_Maximum()
	{		
		CheckCamHandle("GetLensFocusMovementValue" "_Maximum");
		int val=0;
		CheckCamHandle("GetLensFocusMovementValue");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LENS_FOCUS_MOVEMENT_VALUE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetLensFocusMovementValue" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetLensFocusMovementValue_Minimum()
	{
		CheckCamHandle("GetLensFocusMovementValue" "_Minimum");
		int val=0;
		CheckCamHandle("GetLensFocusMovementValue");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LENS_FOCUS_MOVEMENT_VALUE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetLensFocusMovementValue" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetLensFocusMovementValue_Increment()
	{
		CheckCamHandle("GetLensFocusMovementValue" "_Increment");
		int val=0;
		CheckCamHandle("GetLensFocusMovementValue");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LENS_FOCUS_MOVEMENT_VALUE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetLensFocusMovementValue" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetLensFocusMovementValue(int LensFocusMovementValue)
	{
		
		CheckCamHandleInt("SetLensFocusMovementValue",LensFocusMovementValue);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_LENS_FOCUS_MOVEMENT_VALUE, LensFocusMovementValue);
		CheckResult(res,"SetLensFocusMovementValue");
	}
	 
	
	// Moves lens focus motor by steps set in XI_PRM_LENS_FOCUS_MOVEMENT_VALUE. (XI_PRM_LENS_FOCUS_MOVE)
	void xiAPIplus_Camera::SetLensFocusMove(int LensFocusMove)
	{
		
		CheckCamHandleInt("SetLensFocusMove",LensFocusMove);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_LENS_FOCUS_MOVE, LensFocusMove);
		CheckResult(res,"SetLensFocusMove");
	}
	 
	
	// Lens focal distance in mm. (XI_PRM_LENS_FOCAL_LENGTH)
	float xiAPIplus_Camera::GetLensFocalLength()
	{
		float val=0;
		
		CheckCamHandle("GetLensFocalLength");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_LENS_FOCAL_LENGTH, &val);
		CheckResult(res,"GetLensFocalLength");
		return val;
	}

	float xiAPIplus_Camera::GetLensFocalLength_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetLensFocalLength" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_LENS_FOCAL_LENGTH XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetLensFocalLength" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetLensFocalLength_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetLensFocalLength" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_LENS_FOCAL_LENGTH XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetLensFocalLength" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetLensFocalLength_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetLensFocalLength" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_LENS_FOCAL_LENGTH XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetLensFocalLength" "_Increment");
		return val;
	}
	 
	
	// Selects the current feature which is accessible by XI_PRM_LENS_FEATURE. (XI_PRM_LENS_FEATURE_SELECTOR)
	XI_LENS_FEATURE xiAPIplus_Camera::GetLensFeatureSelector()
	{
		int val=0;
		
		CheckCamHandle("GetLensFeatureSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LENS_FEATURE_SELECTOR, &val);
		CheckResult(res,"GetLensFeatureSelector");
		return (XI_LENS_FEATURE)val;
	}
	
	XI_LENS_FEATURE xiAPIplus_Camera::GetLensFeatureSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetLensFeatureSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LENS_FEATURE_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetLensFeatureSelector" "_Maximum");
		return (XI_LENS_FEATURE)val;
	}
	
	XI_LENS_FEATURE xiAPIplus_Camera::GetLensFeatureSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetLensFeatureSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LENS_FEATURE_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetLensFeatureSelector" "_Minimum");
		return (XI_LENS_FEATURE)val;
	}
	
	int xiAPIplus_Camera::GetLensFeatureSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetLensFeatureSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LENS_FEATURE_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetLensFeatureSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetLensFeatureSelector(XI_LENS_FEATURE LensFeatureSelector)
	{
		
		CheckCamHandleInt("SetLensFeatureSelector",(int)LensFeatureSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_LENS_FEATURE_SELECTOR, LensFeatureSelector);
		CheckResult(res,"SetLensFeatureSelector");
	}
	 
	
	// Allows access to lens feature value currently selected by XI_PRM_LENS_FEATURE_SELECTOR. (XI_PRM_LENS_FEATURE)
	float xiAPIplus_Camera::GetLensFeature()
	{
		float val=0;
		
		CheckCamHandle("GetLensFeature");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_LENS_FEATURE, &val);
		CheckResult(res,"GetLensFeature");
		return val;
	}

	float xiAPIplus_Camera::GetLensFeature_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetLensFeature" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_LENS_FEATURE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetLensFeature" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetLensFeature_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetLensFeature" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_LENS_FEATURE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetLensFeature" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetLensFeature_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetLensFeature" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_LENS_FEATURE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetLensFeature" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetLensFeature(float LensFeature)
	{
		
		CheckCamHandle("SetLensFeature");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_LENS_FEATURE, LensFeature);
		CheckResult(res,"SetLensFeature");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Device info parameters
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Return device name (XI_PRM_DEVICE_NAME)
	void xiAPIplus_Camera::GetCameraName(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetCameraName");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_DEVICE_NAME, buffer, buffer_length);
		CheckResult(res,"GetCameraName");
	}
	 
	
	// Return device type (XI_PRM_DEVICE_TYPE)
	void xiAPIplus_Camera::GetCameraType(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetCameraType");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_DEVICE_TYPE, buffer, buffer_length);
		CheckResult(res,"GetCameraType");
	}
	 
	
	// Return device model id (XI_PRM_DEVICE_MODEL_ID)
	// integer type
	int xiAPIplus_Camera::GetModelId()
	{
		CheckCamHandle("GetModelId");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEVICE_MODEL_ID, &val);
		CheckResult(res,"GetModelId");
		return val;	
	}
	int xiAPIplus_Camera::GetModelId_Maximum()
	{		
		CheckCamHandle("GetModelId" "_Maximum");
		int val=0;
		CheckCamHandle("GetModelId");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEVICE_MODEL_ID XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetModelId" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetModelId_Minimum()
	{
		CheckCamHandle("GetModelId" "_Minimum");
		int val=0;
		CheckCamHandle("GetModelId");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEVICE_MODEL_ID XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetModelId" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetModelId_Increment()
	{
		CheckCamHandle("GetModelId" "_Increment");
		int val=0;
		CheckCamHandle("GetModelId");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEVICE_MODEL_ID XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetModelId" "_Increment");
		return val;		
	}
	 
	
	// Return device sensor model id (XI_PRM_SENSOR_MODEL_ID)
	// integer type
	int xiAPIplus_Camera::GetSensorId()
	{
		CheckCamHandle("GetSensorId");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_MODEL_ID, &val);
		CheckResult(res,"GetSensorId");
		return val;	
	}
	int xiAPIplus_Camera::GetSensorId_Maximum()
	{		
		CheckCamHandle("GetSensorId" "_Maximum");
		int val=0;
		CheckCamHandle("GetSensorId");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_MODEL_ID XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetSensorId" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetSensorId_Minimum()
	{
		CheckCamHandle("GetSensorId" "_Minimum");
		int val=0;
		CheckCamHandle("GetSensorId");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_MODEL_ID XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetSensorId" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetSensorId_Increment()
	{
		CheckCamHandle("GetSensorId" "_Increment");
		int val=0;
		CheckCamHandle("GetSensorId");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_MODEL_ID XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetSensorId" "_Increment");
		return val;		
	}
	 
	
	// Return device serial number (XI_PRM_DEVICE_SN)
	void xiAPIplus_Camera::GetSerialNumber(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetSerialNumber");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_DEVICE_SN, buffer, buffer_length);
		CheckResult(res,"GetSerialNumber");
	}
	 
	
	// Return sensor serial number (XI_PRM_DEVICE_SENS_SN)
	void xiAPIplus_Camera::GetSensorSerialNumber(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetSensorSerialNumber");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_DEVICE_SENS_SN, buffer, buffer_length);
		CheckResult(res,"GetSensorSerialNumber");
	}
	 
	
	// Return device system instance path. (XI_PRM_DEVICE_INSTANCE_PATH)
	void xiAPIplus_Camera::GetDevicePath(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetDevicePath");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_DEVICE_INSTANCE_PATH, buffer, buffer_length);
		CheckResult(res,"GetDevicePath");
	}
	 
	
	// Represents the location of the device in the device tree. (XI_PRM_DEVICE_LOCATION_PATH)
	void xiAPIplus_Camera::GetDeviceLocPath(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetDeviceLocPath");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_DEVICE_LOCATION_PATH, buffer, buffer_length);
		CheckResult(res,"GetDeviceLocPath");
	}
	 
	
	// Return custom ID of camera. (XI_PRM_DEVICE_USER_ID)
	void xiAPIplus_Camera::GetUserId(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetUserId");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_DEVICE_USER_ID, buffer, buffer_length);
		CheckResult(res,"GetUserId");
	}
	 
	
	// Return device capability description XML. (XI_PRM_DEVICE_MANIFEST)
	void xiAPIplus_Camera::GetDeviceManifest(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetDeviceManifest");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_DEVICE_MANIFEST, buffer, buffer_length);
		CheckResult(res,"GetDeviceManifest");
	}
	 
	
	// User image data at image header to track parameters synchronization. (XI_PRM_IMAGE_USER_DATA)
	// integer type
	int xiAPIplus_Camera::GetImageUserData()
	{
		CheckCamHandle("GetImageUserData");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_USER_DATA, &val);
		CheckResult(res,"GetImageUserData");
		return val;	
	}
	int xiAPIplus_Camera::GetImageUserData_Maximum()
	{		
		CheckCamHandle("GetImageUserData" "_Maximum");
		int val=0;
		CheckCamHandle("GetImageUserData");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_USER_DATA XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetImageUserData" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetImageUserData_Minimum()
	{
		CheckCamHandle("GetImageUserData" "_Minimum");
		int val=0;
		CheckCamHandle("GetImageUserData");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_USER_DATA XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetImageUserData" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetImageUserData_Increment()
	{
		CheckCamHandle("GetImageUserData" "_Increment");
		int val=0;
		CheckCamHandle("GetImageUserData");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_USER_DATA XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetImageUserData" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetImageUserData(int ImageUserData)
	{
		
		CheckCamHandleInt("SetImageUserData",ImageUserData);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_IMAGE_USER_DATA, ImageUserData);
		CheckResult(res,"SetImageUserData");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Device acquisition settings
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// The alpha channel of RGB32 output image format. (XI_PRM_IMAGE_DATA_FORMAT_RGB32_ALPHA)
	// integer type
	int xiAPIplus_Camera::GetImageDataFormatRGB32Alpha()
	{
		CheckCamHandle("GetImageDataFormatRGB32Alpha");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_DATA_FORMAT_RGB32_ALPHA, &val);
		CheckResult(res,"GetImageDataFormatRGB32Alpha");
		return val;	
	}
	int xiAPIplus_Camera::GetImageDataFormatRGB32Alpha_Maximum()
	{		
		CheckCamHandle("GetImageDataFormatRGB32Alpha" "_Maximum");
		int val=0;
		CheckCamHandle("GetImageDataFormatRGB32Alpha");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_DATA_FORMAT_RGB32_ALPHA XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetImageDataFormatRGB32Alpha" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetImageDataFormatRGB32Alpha_Minimum()
	{
		CheckCamHandle("GetImageDataFormatRGB32Alpha" "_Minimum");
		int val=0;
		CheckCamHandle("GetImageDataFormatRGB32Alpha");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_DATA_FORMAT_RGB32_ALPHA XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetImageDataFormatRGB32Alpha" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetImageDataFormatRGB32Alpha_Increment()
	{
		CheckCamHandle("GetImageDataFormatRGB32Alpha" "_Increment");
		int val=0;
		CheckCamHandle("GetImageDataFormatRGB32Alpha");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_DATA_FORMAT_RGB32_ALPHA XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetImageDataFormatRGB32Alpha" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetImageDataFormatRGB32Alpha(int ImageDataFormatRGB32Alpha)
	{
		
		CheckCamHandleInt("SetImageDataFormatRGB32Alpha",ImageDataFormatRGB32Alpha);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_IMAGE_DATA_FORMAT_RGB32_ALPHA, ImageDataFormatRGB32Alpha);
		CheckResult(res,"SetImageDataFormatRGB32Alpha");
	}
	 
	
	// Buffer size in bytes sufficient for output image returned by xiGetImage (XI_PRM_IMAGE_PAYLOAD_SIZE)
	// integer type
	int xiAPIplus_Camera::GetImagePayloadSize()
	{
		CheckCamHandle("GetImagePayloadSize");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_PAYLOAD_SIZE, &val);
		CheckResult(res,"GetImagePayloadSize");
		return val;	
	}
	int xiAPIplus_Camera::GetImagePayloadSize_Maximum()
	{		
		CheckCamHandle("GetImagePayloadSize" "_Maximum");
		int val=0;
		CheckCamHandle("GetImagePayloadSize");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_PAYLOAD_SIZE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetImagePayloadSize" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetImagePayloadSize_Minimum()
	{
		CheckCamHandle("GetImagePayloadSize" "_Minimum");
		int val=0;
		CheckCamHandle("GetImagePayloadSize");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_PAYLOAD_SIZE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetImagePayloadSize" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetImagePayloadSize_Increment()
	{
		CheckCamHandle("GetImagePayloadSize" "_Increment");
		int val=0;
		CheckCamHandle("GetImagePayloadSize");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_PAYLOAD_SIZE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetImagePayloadSize" "_Increment");
		return val;		
	}
	 
	
	// Current format of pixels on transport layer. (XI_PRM_TRANSPORT_PIXEL_FORMAT)
	XI_GenTL_Image_Format_e xiAPIplus_Camera::GetTransportPixelFormat()
	{
		int val=0;
		
		CheckCamHandle("GetTransportPixelFormat");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRANSPORT_PIXEL_FORMAT, &val);
		CheckResult(res,"GetTransportPixelFormat");
		return (XI_GenTL_Image_Format_e)val;
	}
	
	XI_GenTL_Image_Format_e xiAPIplus_Camera::GetTransportPixelFormat_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetTransportPixelFormat" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRANSPORT_PIXEL_FORMAT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTransportPixelFormat" "_Maximum");
		return (XI_GenTL_Image_Format_e)val;
	}
	
	XI_GenTL_Image_Format_e xiAPIplus_Camera::GetTransportPixelFormat_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetTransportPixelFormat" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRANSPORT_PIXEL_FORMAT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTransportPixelFormat" "_Minimum");
		return (XI_GenTL_Image_Format_e)val;
	}
	
	int xiAPIplus_Camera::GetTransportPixelFormat_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetTransportPixelFormat" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRANSPORT_PIXEL_FORMAT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTransportPixelFormat" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetTransportPixelFormat(XI_GenTL_Image_Format_e TransportPixelFormat)
	{
		
		CheckCamHandleInt("SetTransportPixelFormat",(int)TransportPixelFormat);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_TRANSPORT_PIXEL_FORMAT, TransportPixelFormat);
		CheckResult(res,"SetTransportPixelFormat");
	}
	 
	
	// Target selector for data - CPU RAM or GPU RAM (XI_PRM_TRANSPORT_DATA_TARGET)
	XI_TRANSPORT_DATA_TARGET_MODE xiAPIplus_Camera::GetTransportDataTarget()
	{
		int val=0;
		
		CheckCamHandle("GetTransportDataTarget");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRANSPORT_DATA_TARGET, &val);
		CheckResult(res,"GetTransportDataTarget");
		return (XI_TRANSPORT_DATA_TARGET_MODE)val;
	}
	
	XI_TRANSPORT_DATA_TARGET_MODE xiAPIplus_Camera::GetTransportDataTarget_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetTransportDataTarget" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRANSPORT_DATA_TARGET XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTransportDataTarget" "_Maximum");
		return (XI_TRANSPORT_DATA_TARGET_MODE)val;
	}
	
	XI_TRANSPORT_DATA_TARGET_MODE xiAPIplus_Camera::GetTransportDataTarget_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetTransportDataTarget" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRANSPORT_DATA_TARGET XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTransportDataTarget" "_Minimum");
		return (XI_TRANSPORT_DATA_TARGET_MODE)val;
	}
	
	int xiAPIplus_Camera::GetTransportDataTarget_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetTransportDataTarget" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRANSPORT_DATA_TARGET XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTransportDataTarget" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetTransportDataTarget(XI_TRANSPORT_DATA_TARGET_MODE TransportDataTarget)
	{
		
		CheckCamHandleInt("SetTransportDataTarget",(int)TransportDataTarget);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_TRANSPORT_DATA_TARGET, TransportDataTarget);
		CheckResult(res,"SetTransportDataTarget");
	}
	 
	
	// Sensor clock frequency in Hz. (XI_PRM_SENSOR_CLOCK_FREQ_HZ)
	float xiAPIplus_Camera::GetSensorClockFrequencyHz()
	{
		float val=0;
		
		CheckCamHandle("GetSensorClockFrequencyHz");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_SENSOR_CLOCK_FREQ_HZ, &val);
		CheckResult(res,"GetSensorClockFrequencyHz");
		return val;
	}

	float xiAPIplus_Camera::GetSensorClockFrequencyHz_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetSensorClockFrequencyHz" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_SENSOR_CLOCK_FREQ_HZ XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetSensorClockFrequencyHz" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetSensorClockFrequencyHz_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetSensorClockFrequencyHz" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_SENSOR_CLOCK_FREQ_HZ XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetSensorClockFrequencyHz" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetSensorClockFrequencyHz_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetSensorClockFrequencyHz" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_SENSOR_CLOCK_FREQ_HZ XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetSensorClockFrequencyHz" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetSensorClockFrequencyHz(float SensorClockFrequencyHz)
	{
		
		CheckCamHandle("SetSensorClockFrequencyHz");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_SENSOR_CLOCK_FREQ_HZ, SensorClockFrequencyHz);
		CheckResult(res,"SetSensorClockFrequencyHz");
	}
	 
	
	// Sensor clock frequency index. Sensor with selected frequencies have possibility to set the frequency only by this index. (XI_PRM_SENSOR_CLOCK_FREQ_INDEX)
	// integer type
	int xiAPIplus_Camera::GetSensorClockFrequencyIndex()
	{
		CheckCamHandle("GetSensorClockFrequencyIndex");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_CLOCK_FREQ_INDEX, &val);
		CheckResult(res,"GetSensorClockFrequencyIndex");
		return val;	
	}
	int xiAPIplus_Camera::GetSensorClockFrequencyIndex_Maximum()
	{		
		CheckCamHandle("GetSensorClockFrequencyIndex" "_Maximum");
		int val=0;
		CheckCamHandle("GetSensorClockFrequencyIndex");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_CLOCK_FREQ_INDEX XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetSensorClockFrequencyIndex" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetSensorClockFrequencyIndex_Minimum()
	{
		CheckCamHandle("GetSensorClockFrequencyIndex" "_Minimum");
		int val=0;
		CheckCamHandle("GetSensorClockFrequencyIndex");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_CLOCK_FREQ_INDEX XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetSensorClockFrequencyIndex" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetSensorClockFrequencyIndex_Increment()
	{
		CheckCamHandle("GetSensorClockFrequencyIndex" "_Increment");
		int val=0;
		CheckCamHandle("GetSensorClockFrequencyIndex");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_CLOCK_FREQ_INDEX XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetSensorClockFrequencyIndex" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetSensorClockFrequencyIndex(int SensorClockFrequencyIndex)
	{
		
		CheckCamHandleInt("SetSensorClockFrequencyIndex",SensorClockFrequencyIndex);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_SENSOR_CLOCK_FREQ_INDEX, SensorClockFrequencyIndex);
		CheckResult(res,"SetSensorClockFrequencyIndex");
	}
	 
	
	// Number of output channels from sensor used for data transfer. (XI_PRM_SENSOR_OUTPUT_CHANNEL_COUNT)
	XI_SENSOR_OUTPUT_CHANNEL_COUNT xiAPIplus_Camera::GetSensorOutputChannelCount()
	{
		int val=0;
		
		CheckCamHandle("GetSensorOutputChannelCount");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_OUTPUT_CHANNEL_COUNT, &val);
		CheckResult(res,"GetSensorOutputChannelCount");
		return (XI_SENSOR_OUTPUT_CHANNEL_COUNT)val;
	}
	
	XI_SENSOR_OUTPUT_CHANNEL_COUNT xiAPIplus_Camera::GetSensorOutputChannelCount_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetSensorOutputChannelCount" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_OUTPUT_CHANNEL_COUNT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetSensorOutputChannelCount" "_Maximum");
		return (XI_SENSOR_OUTPUT_CHANNEL_COUNT)val;
	}
	
	XI_SENSOR_OUTPUT_CHANNEL_COUNT xiAPIplus_Camera::GetSensorOutputChannelCount_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetSensorOutputChannelCount" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_OUTPUT_CHANNEL_COUNT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetSensorOutputChannelCount" "_Minimum");
		return (XI_SENSOR_OUTPUT_CHANNEL_COUNT)val;
	}
	
	int xiAPIplus_Camera::GetSensorOutputChannelCount_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetSensorOutputChannelCount" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_OUTPUT_CHANNEL_COUNT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetSensorOutputChannelCount" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetSensorOutputChannelCount(XI_SENSOR_OUTPUT_CHANNEL_COUNT SensorOutputChannelCount)
	{
		
		CheckCamHandleInt("SetSensorOutputChannelCount",(int)SensorOutputChannelCount);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_SENSOR_OUTPUT_CHANNEL_COUNT, SensorOutputChannelCount);
		CheckResult(res,"SetSensorOutputChannelCount");
	}
	 
	
	// Define framerate in Hz (XI_PRM_FRAMERATE)
	float xiAPIplus_Camera::GetFrameRate()
	{
		float val=0;
		
		CheckCamHandle("GetFrameRate");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_FRAMERATE, &val);
		CheckResult(res,"GetFrameRate");
		return val;
	}

	float xiAPIplus_Camera::GetFrameRate_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetFrameRate" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_FRAMERATE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetFrameRate" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetFrameRate_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetFrameRate" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_FRAMERATE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetFrameRate" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetFrameRate_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetFrameRate" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_FRAMERATE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetFrameRate" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetFrameRate(float FrameRate)
	{
		
		CheckCamHandle("SetFrameRate");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_FRAMERATE, FrameRate);
		CheckResult(res,"SetFrameRate");
	}
	 
	
	// Select counter (XI_PRM_COUNTER_SELECTOR)
	XI_COUNTER_SELECTOR xiAPIplus_Camera::GetCounterSelector()
	{
		int val=0;
		
		CheckCamHandle("GetCounterSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COUNTER_SELECTOR, &val);
		CheckResult(res,"GetCounterSelector");
		return (XI_COUNTER_SELECTOR)val;
	}
	
	XI_COUNTER_SELECTOR xiAPIplus_Camera::GetCounterSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetCounterSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COUNTER_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetCounterSelector" "_Maximum");
		return (XI_COUNTER_SELECTOR)val;
	}
	
	XI_COUNTER_SELECTOR xiAPIplus_Camera::GetCounterSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetCounterSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COUNTER_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetCounterSelector" "_Minimum");
		return (XI_COUNTER_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetCounterSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetCounterSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COUNTER_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetCounterSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetCounterSelector(XI_COUNTER_SELECTOR CounterSelector)
	{
		
		CheckCamHandleInt("SetCounterSelector",(int)CounterSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_COUNTER_SELECTOR, CounterSelector);
		CheckResult(res,"SetCounterSelector");
	}
	 
	
	// Counter status (XI_PRM_COUNTER_VALUE)
	// integer type
	int xiAPIplus_Camera::GetCounterValue()
	{
		CheckCamHandle("GetCounterValue");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COUNTER_VALUE, &val);
		CheckResult(res,"GetCounterValue");
		return val;	
	}
	int xiAPIplus_Camera::GetCounterValue_Maximum()
	{		
		CheckCamHandle("GetCounterValue" "_Maximum");
		int val=0;
		CheckCamHandle("GetCounterValue");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COUNTER_VALUE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetCounterValue" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetCounterValue_Minimum()
	{
		CheckCamHandle("GetCounterValue" "_Minimum");
		int val=0;
		CheckCamHandle("GetCounterValue");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COUNTER_VALUE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetCounterValue" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetCounterValue_Increment()
	{
		CheckCamHandle("GetCounterValue" "_Increment");
		int val=0;
		CheckCamHandle("GetCounterValue");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COUNTER_VALUE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetCounterValue" "_Increment");
		return val;		
	}
	 
	
	// Type of sensor frames timing. (XI_PRM_ACQ_TIMING_MODE)
	XI_ACQ_TIMING_MODE xiAPIplus_Camera::GetAcquisitionTimingMode()
	{
		int val=0;
		
		CheckCamHandle("GetAcquisitionTimingMode");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TIMING_MODE, &val);
		CheckResult(res,"GetAcquisitionTimingMode");
		return (XI_ACQ_TIMING_MODE)val;
	}
	
	XI_ACQ_TIMING_MODE xiAPIplus_Camera::GetAcquisitionTimingMode_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetAcquisitionTimingMode" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TIMING_MODE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAcquisitionTimingMode" "_Maximum");
		return (XI_ACQ_TIMING_MODE)val;
	}
	
	XI_ACQ_TIMING_MODE xiAPIplus_Camera::GetAcquisitionTimingMode_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetAcquisitionTimingMode" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TIMING_MODE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAcquisitionTimingMode" "_Minimum");
		return (XI_ACQ_TIMING_MODE)val;
	}
	
	int xiAPIplus_Camera::GetAcquisitionTimingMode_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetAcquisitionTimingMode" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TIMING_MODE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAcquisitionTimingMode" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetAcquisitionTimingMode(XI_ACQ_TIMING_MODE AcquisitionTimingMode)
	{
		
		CheckCamHandleInt("SetAcquisitionTimingMode",(int)AcquisitionTimingMode);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_ACQ_TIMING_MODE, AcquisitionTimingMode);
		CheckResult(res,"SetAcquisitionTimingMode");
	}
	 
	
	// Measure and return available interface bandwidth(int Megabits) (XI_PRM_AVAILABLE_BANDWIDTH)
	// integer type
	int xiAPIplus_Camera::GetBandwidthAvailable()
	{
		CheckCamHandle("GetBandwidthAvailable");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AVAILABLE_BANDWIDTH, &val);
		CheckResult(res,"GetBandwidthAvailable");
		return val;	
	}
	int xiAPIplus_Camera::GetBandwidthAvailable_Maximum()
	{		
		CheckCamHandle("GetBandwidthAvailable" "_Maximum");
		int val=0;
		CheckCamHandle("GetBandwidthAvailable");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AVAILABLE_BANDWIDTH XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetBandwidthAvailable" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetBandwidthAvailable_Minimum()
	{
		CheckCamHandle("GetBandwidthAvailable" "_Minimum");
		int val=0;
		CheckCamHandle("GetBandwidthAvailable");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AVAILABLE_BANDWIDTH XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetBandwidthAvailable" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetBandwidthAvailable_Increment()
	{
		CheckCamHandle("GetBandwidthAvailable" "_Increment");
		int val=0;
		CheckCamHandle("GetBandwidthAvailable");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_AVAILABLE_BANDWIDTH XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetBandwidthAvailable" "_Increment");
		return val;		
	}
	 
	
	// Data move policy (XI_PRM_BUFFER_POLICY)
	XI_BP xiAPIplus_Camera::GetBufferPolicy()
	{
		int val=0;
		
		CheckCamHandle("GetBufferPolicy");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BUFFER_POLICY, &val);
		CheckResult(res,"GetBufferPolicy");
		return (XI_BP)val;
	}
	
	XI_BP xiAPIplus_Camera::GetBufferPolicy_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetBufferPolicy" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BUFFER_POLICY XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetBufferPolicy" "_Maximum");
		return (XI_BP)val;
	}
	
	XI_BP xiAPIplus_Camera::GetBufferPolicy_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetBufferPolicy" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BUFFER_POLICY XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetBufferPolicy" "_Minimum");
		return (XI_BP)val;
	}
	
	int xiAPIplus_Camera::GetBufferPolicy_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetBufferPolicy" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BUFFER_POLICY XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetBufferPolicy" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetBufferPolicy(XI_BP BufferPolicy)
	{
		
		CheckCamHandleInt("SetBufferPolicy",(int)BufferPolicy);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_BUFFER_POLICY, BufferPolicy);
		CheckResult(res,"SetBufferPolicy");
	}
	 
	
	// Activates LUT. (XI_PRM_LUT_EN)
	bool xiAPIplus_Camera::IsLookUpTable()
	{
		int val=0;
		
		CheckCamHandle("IsLookUpTable");
		
		xiGetParamInt(camera_handle, XI_PRM_LUT_EN, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableLookUpTable()
	{
		
		CheckCamHandle("IsLookUpTable");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_LUT_EN, XI_ON);
		CheckResult(res,"EnableLookUpTable");
	}

	void xiAPIplus_Camera::DisableLookUpTable()
	{
		
		CheckCamHandle("DisableLookUpTable");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_LUT_EN, XI_OFF);
		CheckResult(res,"DisableLookUpTable");
	}	
	 
	
	// Control the index (offset) of the coefficient to access in the LUT. (XI_PRM_LUT_INDEX)
	// integer type
	int xiAPIplus_Camera::GetLookUpTableIndex()
	{
		CheckCamHandle("GetLookUpTableIndex");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LUT_INDEX, &val);
		CheckResult(res,"GetLookUpTableIndex");
		return val;	
	}
	int xiAPIplus_Camera::GetLookUpTableIndex_Maximum()
	{		
		CheckCamHandle("GetLookUpTableIndex" "_Maximum");
		int val=0;
		CheckCamHandle("GetLookUpTableIndex");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LUT_INDEX XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetLookUpTableIndex" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetLookUpTableIndex_Minimum()
	{
		CheckCamHandle("GetLookUpTableIndex" "_Minimum");
		int val=0;
		CheckCamHandle("GetLookUpTableIndex");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LUT_INDEX XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetLookUpTableIndex" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetLookUpTableIndex_Increment()
	{
		CheckCamHandle("GetLookUpTableIndex" "_Increment");
		int val=0;
		CheckCamHandle("GetLookUpTableIndex");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LUT_INDEX XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetLookUpTableIndex" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetLookUpTableIndex(int LookUpTableIndex)
	{
		
		CheckCamHandleInt("SetLookUpTableIndex",LookUpTableIndex);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_LUT_INDEX, LookUpTableIndex);
		CheckResult(res,"SetLookUpTableIndex");
	}
	 
	
	// Value at entry LUTIndex of the LUT (XI_PRM_LUT_VALUE)
	// integer type
	int xiAPIplus_Camera::GetLookUpTableValue()
	{
		CheckCamHandle("GetLookUpTableValue");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LUT_VALUE, &val);
		CheckResult(res,"GetLookUpTableValue");
		return val;	
	}
	int xiAPIplus_Camera::GetLookUpTableValue_Maximum()
	{		
		CheckCamHandle("GetLookUpTableValue" "_Maximum");
		int val=0;
		CheckCamHandle("GetLookUpTableValue");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LUT_VALUE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetLookUpTableValue" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetLookUpTableValue_Minimum()
	{
		CheckCamHandle("GetLookUpTableValue" "_Minimum");
		int val=0;
		CheckCamHandle("GetLookUpTableValue");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LUT_VALUE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetLookUpTableValue" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetLookUpTableValue_Increment()
	{
		CheckCamHandle("GetLookUpTableValue" "_Increment");
		int val=0;
		CheckCamHandle("GetLookUpTableValue");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_LUT_VALUE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetLookUpTableValue" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetLookUpTableValue(int LookUpTableValue)
	{
		
		CheckCamHandleInt("SetLookUpTableValue",LookUpTableValue);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_LUT_VALUE, LookUpTableValue);
		CheckResult(res,"SetLookUpTableValue");
	}
	 
	
	// Specifies the delay in microseconds (us) to apply after the trigger reception before activating it. (XI_PRM_TRG_DELAY)
	// integer type
	int xiAPIplus_Camera::GetTriggerDelay()
	{
		CheckCamHandle("GetTriggerDelay");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_DELAY, &val);
		CheckResult(res,"GetTriggerDelay");
		return val;	
	}
	int xiAPIplus_Camera::GetTriggerDelay_Maximum()
	{		
		CheckCamHandle("GetTriggerDelay" "_Maximum");
		int val=0;
		CheckCamHandle("GetTriggerDelay");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_DELAY XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTriggerDelay" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetTriggerDelay_Minimum()
	{
		CheckCamHandle("GetTriggerDelay" "_Minimum");
		int val=0;
		CheckCamHandle("GetTriggerDelay");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_DELAY XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTriggerDelay" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetTriggerDelay_Increment()
	{
		CheckCamHandle("GetTriggerDelay" "_Increment");
		int val=0;
		CheckCamHandle("GetTriggerDelay");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TRG_DELAY XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTriggerDelay" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetTriggerDelay(int TriggerDelay)
	{
		
		CheckCamHandleInt("SetTriggerDelay",TriggerDelay);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_TRG_DELAY, TriggerDelay);
		CheckResult(res,"SetTriggerDelay");
	}
	 
	
	// Defines how TimeStamp reset engine will be armed (XI_PRM_TS_RST_MODE)
	XI_TS_RST_MODE xiAPIplus_Camera::GetTimestampResetMode()
	{
		int val=0;
		
		CheckCamHandle("GetTimestampResetMode");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TS_RST_MODE, &val);
		CheckResult(res,"GetTimestampResetMode");
		return (XI_TS_RST_MODE)val;
	}
	
	XI_TS_RST_MODE xiAPIplus_Camera::GetTimestampResetMode_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetTimestampResetMode" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TS_RST_MODE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTimestampResetMode" "_Maximum");
		return (XI_TS_RST_MODE)val;
	}
	
	XI_TS_RST_MODE xiAPIplus_Camera::GetTimestampResetMode_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetTimestampResetMode" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TS_RST_MODE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTimestampResetMode" "_Minimum");
		return (XI_TS_RST_MODE)val;
	}
	
	int xiAPIplus_Camera::GetTimestampResetMode_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetTimestampResetMode" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TS_RST_MODE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTimestampResetMode" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetTimestampResetMode(XI_TS_RST_MODE TimestampResetMode)
	{
		
		CheckCamHandleInt("SetTimestampResetMode",(int)TimestampResetMode);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_TS_RST_MODE, TimestampResetMode);
		CheckResult(res,"SetTimestampResetMode");
	}
	 
	
	// Defines which source will be used for timestamp reset. Writing this parameter will trigger settings of engine (arming) (XI_PRM_TS_RST_SOURCE)
	XI_TS_RST_SOURCE xiAPIplus_Camera::GetTimestampResetSource()
	{
		int val=0;
		
		CheckCamHandle("GetTimestampResetSource");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TS_RST_SOURCE, &val);
		CheckResult(res,"GetTimestampResetSource");
		return (XI_TS_RST_SOURCE)val;
	}
	
	XI_TS_RST_SOURCE xiAPIplus_Camera::GetTimestampResetSource_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetTimestampResetSource" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TS_RST_SOURCE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetTimestampResetSource" "_Maximum");
		return (XI_TS_RST_SOURCE)val;
	}
	
	XI_TS_RST_SOURCE xiAPIplus_Camera::GetTimestampResetSource_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetTimestampResetSource" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TS_RST_SOURCE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetTimestampResetSource" "_Minimum");
		return (XI_TS_RST_SOURCE)val;
	}
	
	int xiAPIplus_Camera::GetTimestampResetSource_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetTimestampResetSource" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_TS_RST_SOURCE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetTimestampResetSource" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetTimestampResetSource(XI_TS_RST_SOURCE TimestampResetSource)
	{
		
		CheckCamHandleInt("SetTimestampResetSource",(int)TimestampResetSource);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_TS_RST_SOURCE, TimestampResetSource);
		CheckResult(res,"SetTimestampResetSource");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Extended Device parameters
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Returns 1 if camera connected and works properly. (XI_PRM_IS_DEVICE_EXIST)
	bool xiAPIplus_Camera::IsExist()
	{
		int val=0;
		
		CheckCamHandle("IsExist");
		
		xiGetParamInt(camera_handle, XI_PRM_IS_DEVICE_EXIST, &val);
		return (val!=0);
	}
	 
	
	// Acquisition buffer size in buffer_size_unit. Default bytes. (XI_PRM_ACQ_BUFFER_SIZE)
	// integer type
	int xiAPIplus_Camera::GetAcquisitionBufferSizeBytes()
	{
		CheckCamHandle("GetAcquisitionBufferSizeBytes");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_BUFFER_SIZE, &val);
		CheckResult(res,"GetAcquisitionBufferSizeBytes");
		return val;	
	}
	int xiAPIplus_Camera::GetAcquisitionBufferSizeBytes_Maximum()
	{		
		CheckCamHandle("GetAcquisitionBufferSizeBytes" "_Maximum");
		int val=0;
		CheckCamHandle("GetAcquisitionBufferSizeBytes");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_BUFFER_SIZE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAcquisitionBufferSizeBytes" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetAcquisitionBufferSizeBytes_Minimum()
	{
		CheckCamHandle("GetAcquisitionBufferSizeBytes" "_Minimum");
		int val=0;
		CheckCamHandle("GetAcquisitionBufferSizeBytes");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_BUFFER_SIZE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAcquisitionBufferSizeBytes" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetAcquisitionBufferSizeBytes_Increment()
	{
		CheckCamHandle("GetAcquisitionBufferSizeBytes" "_Increment");
		int val=0;
		CheckCamHandle("GetAcquisitionBufferSizeBytes");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_BUFFER_SIZE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAcquisitionBufferSizeBytes" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetAcquisitionBufferSizeBytes(int AcquisitionBufferSizeBytes)
	{
		
		CheckCamHandleInt("SetAcquisitionBufferSizeBytes",AcquisitionBufferSizeBytes);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_ACQ_BUFFER_SIZE, AcquisitionBufferSizeBytes);
		CheckResult(res,"SetAcquisitionBufferSizeBytes");
	}
	 
	
	// Acquisition buffer size unit in bytes. Default 1. E.g. Value 1024 means that buffer_size is in KiBytes (XI_PRM_ACQ_BUFFER_SIZE_UNIT)
	// integer type
	int xiAPIplus_Camera::GetAcquisitionBufferSizeBytesUnit()
	{
		CheckCamHandle("GetAcquisitionBufferSizeBytesUnit");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_BUFFER_SIZE_UNIT, &val);
		CheckResult(res,"GetAcquisitionBufferSizeBytesUnit");
		return val;	
	}
	int xiAPIplus_Camera::GetAcquisitionBufferSizeBytesUnit_Maximum()
	{		
		CheckCamHandle("GetAcquisitionBufferSizeBytesUnit" "_Maximum");
		int val=0;
		CheckCamHandle("GetAcquisitionBufferSizeBytesUnit");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_BUFFER_SIZE_UNIT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAcquisitionBufferSizeBytesUnit" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetAcquisitionBufferSizeBytesUnit_Minimum()
	{
		CheckCamHandle("GetAcquisitionBufferSizeBytesUnit" "_Minimum");
		int val=0;
		CheckCamHandle("GetAcquisitionBufferSizeBytesUnit");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_BUFFER_SIZE_UNIT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAcquisitionBufferSizeBytesUnit" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetAcquisitionBufferSizeBytesUnit_Increment()
	{
		CheckCamHandle("GetAcquisitionBufferSizeBytesUnit" "_Increment");
		int val=0;
		CheckCamHandle("GetAcquisitionBufferSizeBytesUnit");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_BUFFER_SIZE_UNIT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAcquisitionBufferSizeBytesUnit" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetAcquisitionBufferSizeBytesUnit(int AcquisitionBufferSizeBytesUnit)
	{
		
		CheckCamHandleInt("SetAcquisitionBufferSizeBytesUnit",AcquisitionBufferSizeBytesUnit);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_ACQ_BUFFER_SIZE_UNIT, AcquisitionBufferSizeBytesUnit);
		CheckResult(res,"SetAcquisitionBufferSizeBytesUnit");
	}
	 
	
	// Acquisition transport buffer size in bytes (XI_PRM_ACQ_TRANSPORT_BUFFER_SIZE)
	// integer type
	int xiAPIplus_Camera::GetAcquisitionTransportBufferSizeBytes()
	{
		CheckCamHandle("GetAcquisitionTransportBufferSizeBytes");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TRANSPORT_BUFFER_SIZE, &val);
		CheckResult(res,"GetAcquisitionTransportBufferSizeBytes");
		return val;	
	}
	int xiAPIplus_Camera::GetAcquisitionTransportBufferSizeBytes_Maximum()
	{		
		CheckCamHandle("GetAcquisitionTransportBufferSizeBytes" "_Maximum");
		int val=0;
		CheckCamHandle("GetAcquisitionTransportBufferSizeBytes");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TRANSPORT_BUFFER_SIZE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAcquisitionTransportBufferSizeBytes" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetAcquisitionTransportBufferSizeBytes_Minimum()
	{
		CheckCamHandle("GetAcquisitionTransportBufferSizeBytes" "_Minimum");
		int val=0;
		CheckCamHandle("GetAcquisitionTransportBufferSizeBytes");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TRANSPORT_BUFFER_SIZE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAcquisitionTransportBufferSizeBytes" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetAcquisitionTransportBufferSizeBytes_Increment()
	{
		CheckCamHandle("GetAcquisitionTransportBufferSizeBytes" "_Increment");
		int val=0;
		CheckCamHandle("GetAcquisitionTransportBufferSizeBytes");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TRANSPORT_BUFFER_SIZE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAcquisitionTransportBufferSizeBytes" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetAcquisitionTransportBufferSizeBytes(int AcquisitionTransportBufferSizeBytes)
	{
		
		CheckCamHandleInt("SetAcquisitionTransportBufferSizeBytes",AcquisitionTransportBufferSizeBytes);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_ACQ_TRANSPORT_BUFFER_SIZE, AcquisitionTransportBufferSizeBytes);
		CheckResult(res,"SetAcquisitionTransportBufferSizeBytes");
	}
	 
	
	// Acquisition transport packet size in bytes (XI_PRM_ACQ_TRANSPORT_PACKET_SIZE)
	// integer type
	int xiAPIplus_Camera::GetAcquisitionTransportPacketSizeBytes()
	{
		CheckCamHandle("GetAcquisitionTransportPacketSizeBytes");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TRANSPORT_PACKET_SIZE, &val);
		CheckResult(res,"GetAcquisitionTransportPacketSizeBytes");
		return val;	
	}
	int xiAPIplus_Camera::GetAcquisitionTransportPacketSizeBytes_Maximum()
	{		
		CheckCamHandle("GetAcquisitionTransportPacketSizeBytes" "_Maximum");
		int val=0;
		CheckCamHandle("GetAcquisitionTransportPacketSizeBytes");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TRANSPORT_PACKET_SIZE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAcquisitionTransportPacketSizeBytes" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetAcquisitionTransportPacketSizeBytes_Minimum()
	{
		CheckCamHandle("GetAcquisitionTransportPacketSizeBytes" "_Minimum");
		int val=0;
		CheckCamHandle("GetAcquisitionTransportPacketSizeBytes");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TRANSPORT_PACKET_SIZE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAcquisitionTransportPacketSizeBytes" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetAcquisitionTransportPacketSizeBytes_Increment()
	{
		CheckCamHandle("GetAcquisitionTransportPacketSizeBytes" "_Increment");
		int val=0;
		CheckCamHandle("GetAcquisitionTransportPacketSizeBytes");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TRANSPORT_PACKET_SIZE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAcquisitionTransportPacketSizeBytes" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetAcquisitionTransportPacketSizeBytes(int AcquisitionTransportPacketSizeBytes)
	{
		
		CheckCamHandleInt("SetAcquisitionTransportPacketSizeBytes",AcquisitionTransportPacketSizeBytes);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_ACQ_TRANSPORT_PACKET_SIZE, AcquisitionTransportPacketSizeBytes);
		CheckResult(res,"SetAcquisitionTransportPacketSizeBytes");
	}
	 
	
	// Queue of field/frame buffers (XI_PRM_BUFFERS_QUEUE_SIZE)
	// integer type
	int xiAPIplus_Camera::GetAcquisitionQueueImagesCount()
	{
		CheckCamHandle("GetAcquisitionQueueImagesCount");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BUFFERS_QUEUE_SIZE, &val);
		CheckResult(res,"GetAcquisitionQueueImagesCount");
		return val;	
	}
	int xiAPIplus_Camera::GetAcquisitionQueueImagesCount_Maximum()
	{		
		CheckCamHandle("GetAcquisitionQueueImagesCount" "_Maximum");
		int val=0;
		CheckCamHandle("GetAcquisitionQueueImagesCount");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BUFFERS_QUEUE_SIZE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAcquisitionQueueImagesCount" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetAcquisitionQueueImagesCount_Minimum()
	{
		CheckCamHandle("GetAcquisitionQueueImagesCount" "_Minimum");
		int val=0;
		CheckCamHandle("GetAcquisitionQueueImagesCount");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BUFFERS_QUEUE_SIZE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAcquisitionQueueImagesCount" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetAcquisitionQueueImagesCount_Increment()
	{
		CheckCamHandle("GetAcquisitionQueueImagesCount" "_Increment");
		int val=0;
		CheckCamHandle("GetAcquisitionQueueImagesCount");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_BUFFERS_QUEUE_SIZE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAcquisitionQueueImagesCount" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetAcquisitionQueueImagesCount(int AcquisitionQueueImagesCount)
	{
		
		CheckCamHandleInt("SetAcquisitionQueueImagesCount",AcquisitionQueueImagesCount);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_BUFFERS_QUEUE_SIZE, AcquisitionQueueImagesCount);
		CheckResult(res,"SetAcquisitionQueueImagesCount");
	}
	 
	
	// Total number of buffers to be committed to transport layer. Increasing can enhance transport capacity. E.g. on USB (XI_PRM_ACQ_TRANSPORT_BUFFER_COMMIT)
	// integer type
	int xiAPIplus_Camera::GetAcquisitionTransportBufferCommit()
	{
		CheckCamHandle("GetAcquisitionTransportBufferCommit");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TRANSPORT_BUFFER_COMMIT, &val);
		CheckResult(res,"GetAcquisitionTransportBufferCommit");
		return val;	
	}
	int xiAPIplus_Camera::GetAcquisitionTransportBufferCommit_Maximum()
	{		
		CheckCamHandle("GetAcquisitionTransportBufferCommit" "_Maximum");
		int val=0;
		CheckCamHandle("GetAcquisitionTransportBufferCommit");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TRANSPORT_BUFFER_COMMIT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAcquisitionTransportBufferCommit" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetAcquisitionTransportBufferCommit_Minimum()
	{
		CheckCamHandle("GetAcquisitionTransportBufferCommit" "_Minimum");
		int val=0;
		CheckCamHandle("GetAcquisitionTransportBufferCommit");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TRANSPORT_BUFFER_COMMIT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAcquisitionTransportBufferCommit" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetAcquisitionTransportBufferCommit_Increment()
	{
		CheckCamHandle("GetAcquisitionTransportBufferCommit" "_Increment");
		int val=0;
		CheckCamHandle("GetAcquisitionTransportBufferCommit");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQ_TRANSPORT_BUFFER_COMMIT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAcquisitionTransportBufferCommit" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetAcquisitionTransportBufferCommit(int AcquisitionTransportBufferCommit)
	{
		
		CheckCamHandleInt("SetAcquisitionTransportBufferCommit",AcquisitionTransportBufferCommit);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_ACQ_TRANSPORT_BUFFER_COMMIT, AcquisitionTransportBufferCommit);
		CheckResult(res,"SetAcquisitionTransportBufferCommit");
	}
	 
	
	// GetImage returns most recent frame (XI_PRM_RECENT_FRAME)
	bool xiAPIplus_Camera::IsSelectRecentImage()
	{
		int val=0;
		
		CheckCamHandle("IsSelectRecentImage");
		
		xiGetParamInt(camera_handle, XI_PRM_RECENT_FRAME, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableSelectRecentImage()
	{
		
		CheckCamHandle("IsSelectRecentImage");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_RECENT_FRAME, XI_ON);
		CheckResult(res,"EnableSelectRecentImage");
	}

	void xiAPIplus_Camera::DisableSelectRecentImage()
	{
		
		CheckCamHandle("DisableSelectRecentImage");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_RECENT_FRAME, XI_OFF);
		CheckResult(res,"DisableSelectRecentImage");
	}	
	 
	
	// Resets the camera to default state. (XI_PRM_DEVICE_RESET)
	void xiAPIplus_Camera::SetDeviceReset(int DeviceReset)
	{
		
		CheckCamHandleInt("SetDeviceReset",DeviceReset);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DEVICE_RESET, DeviceReset);
		CheckResult(res,"SetDeviceReset");
	}
	 
	
	// Enable/disable the Concatenated Images in One Buffer feature (XI_PRM_CONCAT_IMG_MODE)
	bool xiAPIplus_Camera::IsConcatenatedImagesMode()
	{
		int val=0;
		
		CheckCamHandle("IsConcatenatedImagesMode");
		
		xiGetParamInt(camera_handle, XI_PRM_CONCAT_IMG_MODE, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableConcatenatedImagesMode()
	{
		
		CheckCamHandle("IsConcatenatedImagesMode");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_CONCAT_IMG_MODE, XI_ON);
		CheckResult(res,"EnableConcatenatedImagesMode");
	}

	void xiAPIplus_Camera::DisableConcatenatedImagesMode()
	{
		
		CheckCamHandle("DisableConcatenatedImagesMode");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_CONCAT_IMG_MODE, XI_OFF);
		CheckResult(res,"DisableConcatenatedImagesMode");
	}	
	 
	
	// Number of Concatenated Images in One Buffer (XI_PRM_CONCAT_IMG_COUNT)
	// integer type
	int xiAPIplus_Camera::GetConcatenatedImagesCount()
	{
		CheckCamHandle("GetConcatenatedImagesCount");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CONCAT_IMG_COUNT, &val);
		CheckResult(res,"GetConcatenatedImagesCount");
		return val;	
	}
	int xiAPIplus_Camera::GetConcatenatedImagesCount_Maximum()
	{		
		CheckCamHandle("GetConcatenatedImagesCount" "_Maximum");
		int val=0;
		CheckCamHandle("GetConcatenatedImagesCount");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CONCAT_IMG_COUNT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetConcatenatedImagesCount" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetConcatenatedImagesCount_Minimum()
	{
		CheckCamHandle("GetConcatenatedImagesCount" "_Minimum");
		int val=0;
		CheckCamHandle("GetConcatenatedImagesCount");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CONCAT_IMG_COUNT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetConcatenatedImagesCount" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetConcatenatedImagesCount_Increment()
	{
		CheckCamHandle("GetConcatenatedImagesCount" "_Increment");
		int val=0;
		CheckCamHandle("GetConcatenatedImagesCount");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CONCAT_IMG_COUNT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetConcatenatedImagesCount" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetConcatenatedImagesCount(int ConcatenatedImagesCount)
	{
		
		CheckCamHandleInt("SetConcatenatedImagesCount",ConcatenatedImagesCount);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_CONCAT_IMG_COUNT, ConcatenatedImagesCount);
		CheckResult(res,"SetConcatenatedImagesCount");
	}
	 
	
	// Offset between images when feature Concatenated Images in One Buffer is enabled (XI_PRM_CONCAT_IMG_TRANSPORT_IMG_OFFSET)
	// integer type
	int xiAPIplus_Camera::GetConcatenatedImagesTransportImgOffset()
	{
		CheckCamHandle("GetConcatenatedImagesTransportImgOffset");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CONCAT_IMG_TRANSPORT_IMG_OFFSET, &val);
		CheckResult(res,"GetConcatenatedImagesTransportImgOffset");
		return val;	
	}
	int xiAPIplus_Camera::GetConcatenatedImagesTransportImgOffset_Maximum()
	{		
		CheckCamHandle("GetConcatenatedImagesTransportImgOffset" "_Maximum");
		int val=0;
		CheckCamHandle("GetConcatenatedImagesTransportImgOffset");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CONCAT_IMG_TRANSPORT_IMG_OFFSET XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetConcatenatedImagesTransportImgOffset" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetConcatenatedImagesTransportImgOffset_Minimum()
	{
		CheckCamHandle("GetConcatenatedImagesTransportImgOffset" "_Minimum");
		int val=0;
		CheckCamHandle("GetConcatenatedImagesTransportImgOffset");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CONCAT_IMG_TRANSPORT_IMG_OFFSET XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetConcatenatedImagesTransportImgOffset" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetConcatenatedImagesTransportImgOffset_Increment()
	{
		CheckCamHandle("GetConcatenatedImagesTransportImgOffset" "_Increment");
		int val=0;
		CheckCamHandle("GetConcatenatedImagesTransportImgOffset");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_CONCAT_IMG_TRANSPORT_IMG_OFFSET XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetConcatenatedImagesTransportImgOffset" "_Increment");
		return val;		
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Sensor Defects Correction
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Correction of column FPN (XI_PRM_COLUMN_FPN_CORRECTION)
	XI_SWITCH xiAPIplus_Camera::GetColumnFpnCorrection()
	{
		int val=0;
		
		CheckCamHandle("GetColumnFpnCorrection");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COLUMN_FPN_CORRECTION, &val);
		CheckResult(res,"GetColumnFpnCorrection");
		return (XI_SWITCH)val;
	}
	
	XI_SWITCH xiAPIplus_Camera::GetColumnFpnCorrection_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetColumnFpnCorrection" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COLUMN_FPN_CORRECTION XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColumnFpnCorrection" "_Maximum");
		return (XI_SWITCH)val;
	}
	
	XI_SWITCH xiAPIplus_Camera::GetColumnFpnCorrection_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetColumnFpnCorrection" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COLUMN_FPN_CORRECTION XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColumnFpnCorrection" "_Minimum");
		return (XI_SWITCH)val;
	}
	
	int xiAPIplus_Camera::GetColumnFpnCorrection_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetColumnFpnCorrection" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COLUMN_FPN_CORRECTION XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColumnFpnCorrection" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColumnFpnCorrection(XI_SWITCH ColumnFpnCorrection)
	{
		
		CheckCamHandleInt("SetColumnFpnCorrection",(int)ColumnFpnCorrection);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_COLUMN_FPN_CORRECTION, ColumnFpnCorrection);
		CheckResult(res,"SetColumnFpnCorrection");
	}
	 
	
	// Correction of row FPN (XI_PRM_ROW_FPN_CORRECTION)
	XI_SWITCH xiAPIplus_Camera::GetRowFpnCorrection()
	{
		int val=0;
		
		CheckCamHandle("GetRowFpnCorrection");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ROW_FPN_CORRECTION, &val);
		CheckResult(res,"GetRowFpnCorrection");
		return (XI_SWITCH)val;
	}
	
	XI_SWITCH xiAPIplus_Camera::GetRowFpnCorrection_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetRowFpnCorrection" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ROW_FPN_CORRECTION XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetRowFpnCorrection" "_Maximum");
		return (XI_SWITCH)val;
	}
	
	XI_SWITCH xiAPIplus_Camera::GetRowFpnCorrection_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetRowFpnCorrection" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ROW_FPN_CORRECTION XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetRowFpnCorrection" "_Minimum");
		return (XI_SWITCH)val;
	}
	
	int xiAPIplus_Camera::GetRowFpnCorrection_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetRowFpnCorrection" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ROW_FPN_CORRECTION XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetRowFpnCorrection" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetRowFpnCorrection(XI_SWITCH RowFpnCorrection)
	{
		
		CheckCamHandleInt("SetRowFpnCorrection",(int)RowFpnCorrection);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_ROW_FPN_CORRECTION, RowFpnCorrection);
		CheckResult(res,"SetRowFpnCorrection");
	}
	 
	
	// Correction of column black offset (XI_PRM_COLUMN_BLACK_OFFSET_CORRECTION)
	XI_SWITCH xiAPIplus_Camera::GetColumnBlackOffsetCorrection()
	{
		int val=0;
		
		CheckCamHandle("GetColumnBlackOffsetCorrection");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COLUMN_BLACK_OFFSET_CORRECTION, &val);
		CheckResult(res,"GetColumnBlackOffsetCorrection");
		return (XI_SWITCH)val;
	}
	
	XI_SWITCH xiAPIplus_Camera::GetColumnBlackOffsetCorrection_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetColumnBlackOffsetCorrection" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COLUMN_BLACK_OFFSET_CORRECTION XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetColumnBlackOffsetCorrection" "_Maximum");
		return (XI_SWITCH)val;
	}
	
	XI_SWITCH xiAPIplus_Camera::GetColumnBlackOffsetCorrection_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetColumnBlackOffsetCorrection" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COLUMN_BLACK_OFFSET_CORRECTION XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetColumnBlackOffsetCorrection" "_Minimum");
		return (XI_SWITCH)val;
	}
	
	int xiAPIplus_Camera::GetColumnBlackOffsetCorrection_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetColumnBlackOffsetCorrection" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COLUMN_BLACK_OFFSET_CORRECTION XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetColumnBlackOffsetCorrection" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetColumnBlackOffsetCorrection(XI_SWITCH ColumnBlackOffsetCorrection)
	{
		
		CheckCamHandleInt("SetColumnBlackOffsetCorrection",(int)ColumnBlackOffsetCorrection);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_COLUMN_BLACK_OFFSET_CORRECTION, ColumnBlackOffsetCorrection);
		CheckResult(res,"SetColumnBlackOffsetCorrection");
	}
	 
	
	// Correction of row black offset (XI_PRM_ROW_BLACK_OFFSET_CORRECTION)
	XI_SWITCH xiAPIplus_Camera::GetRowBlackOffsetCorrection()
	{
		int val=0;
		
		CheckCamHandle("GetRowBlackOffsetCorrection");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ROW_BLACK_OFFSET_CORRECTION, &val);
		CheckResult(res,"GetRowBlackOffsetCorrection");
		return (XI_SWITCH)val;
	}
	
	XI_SWITCH xiAPIplus_Camera::GetRowBlackOffsetCorrection_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetRowBlackOffsetCorrection" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ROW_BLACK_OFFSET_CORRECTION XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetRowBlackOffsetCorrection" "_Maximum");
		return (XI_SWITCH)val;
	}
	
	XI_SWITCH xiAPIplus_Camera::GetRowBlackOffsetCorrection_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetRowBlackOffsetCorrection" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ROW_BLACK_OFFSET_CORRECTION XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetRowBlackOffsetCorrection" "_Minimum");
		return (XI_SWITCH)val;
	}
	
	int xiAPIplus_Camera::GetRowBlackOffsetCorrection_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetRowBlackOffsetCorrection" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ROW_BLACK_OFFSET_CORRECTION XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetRowBlackOffsetCorrection" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetRowBlackOffsetCorrection(XI_SWITCH RowBlackOffsetCorrection)
	{
		
		CheckCamHandleInt("SetRowBlackOffsetCorrection",(int)RowBlackOffsetCorrection);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_ROW_BLACK_OFFSET_CORRECTION, RowBlackOffsetCorrection);
		CheckResult(res,"SetRowBlackOffsetCorrection");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Sensor features
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Current sensor mode. Allows to select sensor mode by one integer. Setting of this parameter affects: image dimensions and downsampling. (XI_PRM_SENSOR_MODE)
	XI_SENSOR_MODE xiAPIplus_Camera::GetSensorMode()
	{
		int val=0;
		
		CheckCamHandle("GetSensorMode");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_MODE, &val);
		CheckResult(res,"GetSensorMode");
		return (XI_SENSOR_MODE)val;
	}
	
	XI_SENSOR_MODE xiAPIplus_Camera::GetSensorMode_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetSensorMode" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_MODE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetSensorMode" "_Maximum");
		return (XI_SENSOR_MODE)val;
	}
	
	XI_SENSOR_MODE xiAPIplus_Camera::GetSensorMode_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetSensorMode" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_MODE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetSensorMode" "_Minimum");
		return (XI_SENSOR_MODE)val;
	}
	
	int xiAPIplus_Camera::GetSensorMode_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetSensorMode" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_MODE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetSensorMode" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetSensorMode(XI_SENSOR_MODE SensorMode)
	{
		
		CheckCamHandleInt("SetSensorMode",(int)SensorMode);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_SENSOR_MODE, SensorMode);
		CheckResult(res,"SetSensorMode");
	}
	 
	
	// Enable High Dynamic Range feature. (XI_PRM_HDR)
	bool xiAPIplus_Camera::IsHDR()
	{
		int val=0;
		
		CheckCamHandle("IsHDR");
		
		xiGetParamInt(camera_handle, XI_PRM_HDR, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableHDR()
	{
		
		CheckCamHandle("IsHDR");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_HDR, XI_ON);
		CheckResult(res,"EnableHDR");
	}

	void xiAPIplus_Camera::DisableHDR()
	{
		
		CheckCamHandle("DisableHDR");
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_HDR, XI_OFF);
		CheckResult(res,"DisableHDR");
	}	
	 
	
	// The number of kneepoints in the PWLR. (XI_PRM_HDR_KNEEPOINT_COUNT)
	// integer type
	int xiAPIplus_Camera::GetHDR_KNEEPOINT_COUNT()
	{
		CheckCamHandle("GetHDR_KNEEPOINT_COUNT");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HDR_KNEEPOINT_COUNT, &val);
		CheckResult(res,"GetHDR_KNEEPOINT_COUNT");
		return val;	
	}
	int xiAPIplus_Camera::GetHDR_KNEEPOINT_COUNT_Maximum()
	{		
		CheckCamHandle("GetHDR_KNEEPOINT_COUNT" "_Maximum");
		int val=0;
		CheckCamHandle("GetHDR_KNEEPOINT_COUNT");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HDR_KNEEPOINT_COUNT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetHDR_KNEEPOINT_COUNT" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetHDR_KNEEPOINT_COUNT_Minimum()
	{
		CheckCamHandle("GetHDR_KNEEPOINT_COUNT" "_Minimum");
		int val=0;
		CheckCamHandle("GetHDR_KNEEPOINT_COUNT");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HDR_KNEEPOINT_COUNT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetHDR_KNEEPOINT_COUNT" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetHDR_KNEEPOINT_COUNT_Increment()
	{
		CheckCamHandle("GetHDR_KNEEPOINT_COUNT" "_Increment");
		int val=0;
		CheckCamHandle("GetHDR_KNEEPOINT_COUNT");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HDR_KNEEPOINT_COUNT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetHDR_KNEEPOINT_COUNT" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetHDR_KNEEPOINT_COUNT(int HDR_KNEEPOINT_COUNT)
	{
		
		CheckCamHandleInt("SetHDR_KNEEPOINT_COUNT",HDR_KNEEPOINT_COUNT);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_HDR_KNEEPOINT_COUNT, HDR_KNEEPOINT_COUNT);
		CheckResult(res,"SetHDR_KNEEPOINT_COUNT");
	}
	 
	
	// position of first kneepoint(in % of XI_PRM_EXPOSURE) (XI_PRM_HDR_T1)
	// integer type
	int xiAPIplus_Camera::GetHDRTimeSlope1()
	{
		CheckCamHandle("GetHDRTimeSlope1");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HDR_T1, &val);
		CheckResult(res,"GetHDRTimeSlope1");
		return val;	
	}
	int xiAPIplus_Camera::GetHDRTimeSlope1_Maximum()
	{		
		CheckCamHandle("GetHDRTimeSlope1" "_Maximum");
		int val=0;
		CheckCamHandle("GetHDRTimeSlope1");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HDR_T1 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetHDRTimeSlope1" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetHDRTimeSlope1_Minimum()
	{
		CheckCamHandle("GetHDRTimeSlope1" "_Minimum");
		int val=0;
		CheckCamHandle("GetHDRTimeSlope1");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HDR_T1 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetHDRTimeSlope1" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetHDRTimeSlope1_Increment()
	{
		CheckCamHandle("GetHDRTimeSlope1" "_Increment");
		int val=0;
		CheckCamHandle("GetHDRTimeSlope1");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HDR_T1 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetHDRTimeSlope1" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetHDRTimeSlope1(int HDRTimeSlope1)
	{
		
		CheckCamHandleInt("SetHDRTimeSlope1",HDRTimeSlope1);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_HDR_T1, HDRTimeSlope1);
		CheckResult(res,"SetHDRTimeSlope1");
	}
	 
	
	// position of second kneepoint (in % of XI_PRM_EXPOSURE) (XI_PRM_HDR_T2)
	// integer type
	int xiAPIplus_Camera::GetHDRTimeSlope2()
	{
		CheckCamHandle("GetHDRTimeSlope2");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HDR_T2, &val);
		CheckResult(res,"GetHDRTimeSlope2");
		return val;	
	}
	int xiAPIplus_Camera::GetHDRTimeSlope2_Maximum()
	{		
		CheckCamHandle("GetHDRTimeSlope2" "_Maximum");
		int val=0;
		CheckCamHandle("GetHDRTimeSlope2");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HDR_T2 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetHDRTimeSlope2" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetHDRTimeSlope2_Minimum()
	{
		CheckCamHandle("GetHDRTimeSlope2" "_Minimum");
		int val=0;
		CheckCamHandle("GetHDRTimeSlope2");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HDR_T2 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetHDRTimeSlope2" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetHDRTimeSlope2_Increment()
	{
		CheckCamHandle("GetHDRTimeSlope2" "_Increment");
		int val=0;
		CheckCamHandle("GetHDRTimeSlope2");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_HDR_T2 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetHDRTimeSlope2" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetHDRTimeSlope2(int HDRTimeSlope2)
	{
		
		CheckCamHandleInt("SetHDRTimeSlope2",HDRTimeSlope2);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_HDR_T2, HDRTimeSlope2);
		CheckResult(res,"SetHDRTimeSlope2");
	}
	 
	
	// value of first kneepoint (% of sensor saturation) (XI_PRM_KNEEPOINT1)
	// integer type
	int xiAPIplus_Camera::GetHDRKnee1Percent()
	{
		CheckCamHandle("GetHDRKnee1Percent");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_KNEEPOINT1, &val);
		CheckResult(res,"GetHDRKnee1Percent");
		return val;	
	}
	int xiAPIplus_Camera::GetHDRKnee1Percent_Maximum()
	{		
		CheckCamHandle("GetHDRKnee1Percent" "_Maximum");
		int val=0;
		CheckCamHandle("GetHDRKnee1Percent");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_KNEEPOINT1 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetHDRKnee1Percent" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetHDRKnee1Percent_Minimum()
	{
		CheckCamHandle("GetHDRKnee1Percent" "_Minimum");
		int val=0;
		CheckCamHandle("GetHDRKnee1Percent");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_KNEEPOINT1 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetHDRKnee1Percent" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetHDRKnee1Percent_Increment()
	{
		CheckCamHandle("GetHDRKnee1Percent" "_Increment");
		int val=0;
		CheckCamHandle("GetHDRKnee1Percent");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_KNEEPOINT1 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetHDRKnee1Percent" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetHDRKnee1Percent(int HDRKnee1Percent)
	{
		
		CheckCamHandleInt("SetHDRKnee1Percent",HDRKnee1Percent);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_KNEEPOINT1, HDRKnee1Percent);
		CheckResult(res,"SetHDRKnee1Percent");
	}
	 
	
	// value of second kneepoint (% of sensor saturation) (XI_PRM_KNEEPOINT2)
	// integer type
	int xiAPIplus_Camera::GetHDRKnee2Percent()
	{
		CheckCamHandle("GetHDRKnee2Percent");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_KNEEPOINT2, &val);
		CheckResult(res,"GetHDRKnee2Percent");
		return val;	
	}
	int xiAPIplus_Camera::GetHDRKnee2Percent_Maximum()
	{		
		CheckCamHandle("GetHDRKnee2Percent" "_Maximum");
		int val=0;
		CheckCamHandle("GetHDRKnee2Percent");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_KNEEPOINT2 XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetHDRKnee2Percent" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetHDRKnee2Percent_Minimum()
	{
		CheckCamHandle("GetHDRKnee2Percent" "_Minimum");
		int val=0;
		CheckCamHandle("GetHDRKnee2Percent");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_KNEEPOINT2 XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetHDRKnee2Percent" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetHDRKnee2Percent_Increment()
	{
		CheckCamHandle("GetHDRKnee2Percent" "_Increment");
		int val=0;
		CheckCamHandle("GetHDRKnee2Percent");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_KNEEPOINT2 XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetHDRKnee2Percent" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetHDRKnee2Percent(int HDRKnee2Percent)
	{
		
		CheckCamHandleInt("SetHDRKnee2Percent",HDRKnee2Percent);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_KNEEPOINT2, HDRKnee2Percent);
		CheckResult(res,"SetHDRKnee2Percent");
	}
	 
	
	// Last image black level counts (same as in XI_IMG). Setting can be used only for Offline Processing. (XI_PRM_IMAGE_BLACK_LEVEL)
	// integer type
	int xiAPIplus_Camera::GetImageBlackLevel()
	{
		CheckCamHandle("GetImageBlackLevel");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_BLACK_LEVEL, &val);
		CheckResult(res,"GetImageBlackLevel");
		return val;	
	}
	int xiAPIplus_Camera::GetImageBlackLevel_Maximum()
	{		
		CheckCamHandle("GetImageBlackLevel" "_Maximum");
		int val=0;
		CheckCamHandle("GetImageBlackLevel");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_BLACK_LEVEL XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetImageBlackLevel" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetImageBlackLevel_Minimum()
	{
		CheckCamHandle("GetImageBlackLevel" "_Minimum");
		int val=0;
		CheckCamHandle("GetImageBlackLevel");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_BLACK_LEVEL XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetImageBlackLevel" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetImageBlackLevel_Increment()
	{
		CheckCamHandle("GetImageBlackLevel" "_Increment");
		int val=0;
		CheckCamHandle("GetImageBlackLevel");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_BLACK_LEVEL XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetImageBlackLevel" "_Increment");
		return val;		
	}
	 
	
	// Defines image area of sensor as output. (XI_PRM_IMAGE_AREA)
	XI_IMAGE_AREA_SELECTOR xiAPIplus_Camera::GetImageArea()
	{
		int val=0;
		
		CheckCamHandle("GetImageArea");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_AREA, &val);
		CheckResult(res,"GetImageArea");
		return (XI_IMAGE_AREA_SELECTOR)val;
	}
	
	XI_IMAGE_AREA_SELECTOR xiAPIplus_Camera::GetImageArea_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetImageArea" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_AREA XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetImageArea" "_Maximum");
		return (XI_IMAGE_AREA_SELECTOR)val;
	}
	
	XI_IMAGE_AREA_SELECTOR xiAPIplus_Camera::GetImageArea_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetImageArea" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_AREA XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetImageArea" "_Minimum");
		return (XI_IMAGE_AREA_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetImageArea_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetImageArea" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_IMAGE_AREA XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetImageArea" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetImageArea(XI_IMAGE_AREA_SELECTOR ImageArea)
	{
		
		CheckCamHandleInt("SetImageArea",(int)ImageArea);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_IMAGE_AREA, ImageArea);
		CheckResult(res,"SetImageArea");
	}
	 
	
	// Sets DualADC Mode (XI_PRM_DUAL_ADC_MODE)
	XI_DUAL_ADC_MODE xiAPIplus_Camera::GetDualADCMode()
	{
		int val=0;
		
		CheckCamHandle("GetDualADCMode");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DUAL_ADC_MODE, &val);
		CheckResult(res,"GetDualADCMode");
		return (XI_DUAL_ADC_MODE)val;
	}
	
	XI_DUAL_ADC_MODE xiAPIplus_Camera::GetDualADCMode_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetDualADCMode" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DUAL_ADC_MODE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDualADCMode" "_Maximum");
		return (XI_DUAL_ADC_MODE)val;
	}
	
	XI_DUAL_ADC_MODE xiAPIplus_Camera::GetDualADCMode_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetDualADCMode" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DUAL_ADC_MODE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDualADCMode" "_Minimum");
		return (XI_DUAL_ADC_MODE)val;
	}
	
	int xiAPIplus_Camera::GetDualADCMode_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetDualADCMode" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DUAL_ADC_MODE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDualADCMode" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetDualADCMode(XI_DUAL_ADC_MODE DualADCMode)
	{
		
		CheckCamHandleInt("SetDualADCMode",(int)DualADCMode);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DUAL_ADC_MODE, DualADCMode);
		CheckResult(res,"SetDualADCMode");
	}
	 
	
	// Sets DualADC Gain Ratio in dB (XI_PRM_DUAL_ADC_GAIN_RATIO)
	float xiAPIplus_Camera::GetDualADCGainRatio()
	{
		float val=0;
		
		CheckCamHandle("GetDualADCGainRatio");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_DUAL_ADC_GAIN_RATIO, &val);
		CheckResult(res,"GetDualADCGainRatio");
		return val;
	}

	float xiAPIplus_Camera::GetDualADCGainRatio_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetDualADCGainRatio" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_DUAL_ADC_GAIN_RATIO XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDualADCGainRatio" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetDualADCGainRatio_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetDualADCGainRatio" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_DUAL_ADC_GAIN_RATIO XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDualADCGainRatio" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetDualADCGainRatio_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetDualADCGainRatio" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_DUAL_ADC_GAIN_RATIO XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDualADCGainRatio" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetDualADCGainRatio(float DualADCGainRatio)
	{
		
		CheckCamHandle("SetDualADCGainRatio");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_DUAL_ADC_GAIN_RATIO, DualADCGainRatio);
		CheckResult(res,"SetDualADCGainRatio");
	}
	 
	
	// Sets DualADC Threshold value (XI_PRM_DUAL_ADC_THRESHOLD)
	// integer type
	int xiAPIplus_Camera::GetDualADCThreshold()
	{
		CheckCamHandle("GetDualADCThreshold");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DUAL_ADC_THRESHOLD, &val);
		CheckResult(res,"GetDualADCThreshold");
		return val;	
	}
	int xiAPIplus_Camera::GetDualADCThreshold_Maximum()
	{		
		CheckCamHandle("GetDualADCThreshold" "_Maximum");
		int val=0;
		CheckCamHandle("GetDualADCThreshold");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DUAL_ADC_THRESHOLD XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDualADCThreshold" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetDualADCThreshold_Minimum()
	{
		CheckCamHandle("GetDualADCThreshold" "_Minimum");
		int val=0;
		CheckCamHandle("GetDualADCThreshold");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DUAL_ADC_THRESHOLD XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDualADCThreshold" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetDualADCThreshold_Increment()
	{
		CheckCamHandle("GetDualADCThreshold" "_Increment");
		int val=0;
		CheckCamHandle("GetDualADCThreshold");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DUAL_ADC_THRESHOLD XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDualADCThreshold" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetDualADCThreshold(int DualADCThreshold)
	{
		
		CheckCamHandleInt("SetDualADCThreshold",DualADCThreshold);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DUAL_ADC_THRESHOLD, DualADCThreshold);
		CheckResult(res,"SetDualADCThreshold");
	}
	 
	
	// Sets Compression Region Selector (XI_PRM_COMPRESSION_REGION_SELECTOR)
	// integer type
	int xiAPIplus_Camera::GetCompressionRegionSelector()
	{
		CheckCamHandle("GetCompressionRegionSelector");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COMPRESSION_REGION_SELECTOR, &val);
		CheckResult(res,"GetCompressionRegionSelector");
		return val;	
	}
	int xiAPIplus_Camera::GetCompressionRegionSelector_Maximum()
	{		
		CheckCamHandle("GetCompressionRegionSelector" "_Maximum");
		int val=0;
		CheckCamHandle("GetCompressionRegionSelector");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COMPRESSION_REGION_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetCompressionRegionSelector" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetCompressionRegionSelector_Minimum()
	{
		CheckCamHandle("GetCompressionRegionSelector" "_Minimum");
		int val=0;
		CheckCamHandle("GetCompressionRegionSelector");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COMPRESSION_REGION_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetCompressionRegionSelector" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetCompressionRegionSelector_Increment()
	{
		CheckCamHandle("GetCompressionRegionSelector" "_Increment");
		int val=0;
		CheckCamHandle("GetCompressionRegionSelector");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_COMPRESSION_REGION_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetCompressionRegionSelector" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetCompressionRegionSelector(int CompressionRegionSelector)
	{
		
		CheckCamHandleInt("SetCompressionRegionSelector",CompressionRegionSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_COMPRESSION_REGION_SELECTOR, CompressionRegionSelector);
		CheckResult(res,"SetCompressionRegionSelector");
	}
	 
	
	// Sets Compression Region Start (XI_PRM_COMPRESSION_REGION_START)
	float xiAPIplus_Camera::GetCompressionRegionStart()
	{
		float val=0;
		
		CheckCamHandle("GetCompressionRegionStart");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_COMPRESSION_REGION_START, &val);
		CheckResult(res,"GetCompressionRegionStart");
		return val;
	}

	float xiAPIplus_Camera::GetCompressionRegionStart_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetCompressionRegionStart" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_COMPRESSION_REGION_START XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetCompressionRegionStart" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetCompressionRegionStart_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetCompressionRegionStart" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_COMPRESSION_REGION_START XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetCompressionRegionStart" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetCompressionRegionStart_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetCompressionRegionStart" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_COMPRESSION_REGION_START XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetCompressionRegionStart" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetCompressionRegionStart(float CompressionRegionStart)
	{
		
		CheckCamHandle("SetCompressionRegionStart");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_COMPRESSION_REGION_START, CompressionRegionStart);
		CheckResult(res,"SetCompressionRegionStart");
	}
	 
	
	// Sets Compression Region Gain (XI_PRM_COMPRESSION_REGION_GAIN)
	float xiAPIplus_Camera::GetCompressionRegionGain()
	{
		float val=0;
		
		CheckCamHandle("GetCompressionRegionGain");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_COMPRESSION_REGION_GAIN, &val);
		CheckResult(res,"GetCompressionRegionGain");
		return val;
	}

	float xiAPIplus_Camera::GetCompressionRegionGain_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetCompressionRegionGain" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_COMPRESSION_REGION_GAIN XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetCompressionRegionGain" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetCompressionRegionGain_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetCompressionRegionGain" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_COMPRESSION_REGION_GAIN XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetCompressionRegionGain" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetCompressionRegionGain_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetCompressionRegionGain" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_COMPRESSION_REGION_GAIN XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetCompressionRegionGain" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetCompressionRegionGain(float CompressionRegionGain)
	{
		
		CheckCamHandle("SetCompressionRegionGain");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_COMPRESSION_REGION_GAIN, CompressionRegionGain);
		CheckResult(res,"SetCompressionRegionGain");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Version info
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Selects module/unit, which version we get. (XI_PRM_VERSION_SELECTOR)
	XI_VERSION xiAPIplus_Camera::GetVersionSelector()
	{
		int val=0;
		
		CheckCamHandle("GetVersionSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_VERSION_SELECTOR, &val);
		CheckResult(res,"GetVersionSelector");
		return (XI_VERSION)val;
	}
	
	XI_VERSION xiAPIplus_Camera::GetVersionSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetVersionSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_VERSION_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetVersionSelector" "_Maximum");
		return (XI_VERSION)val;
	}
	
	XI_VERSION xiAPIplus_Camera::GetVersionSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetVersionSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_VERSION_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetVersionSelector" "_Minimum");
		return (XI_VERSION)val;
	}
	
	int xiAPIplus_Camera::GetVersionSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetVersionSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_VERSION_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetVersionSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetVersionSelector(XI_VERSION VersionSelector)
	{
		
		CheckCamHandleInt("SetVersionSelector",(int)VersionSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_VERSION_SELECTOR, VersionSelector);
		CheckResult(res,"SetVersionSelector");
	}
	 
	
	// Returns version of selected module/unit(XI_PRM_VERSION_SELECTOR). (XI_PRM_VERSION)
	void xiAPIplus_Camera::GetVersion(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetVersion");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_VERSION, buffer, buffer_length);
		CheckResult(res,"GetVersion");
	}
	 
	
	// Returns version of API. (XI_PRM_API_VERSION)
	void xiAPIplus_Camera::GetVersionAPI(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetVersionAPI");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_API_VERSION, buffer, buffer_length);
		CheckResult(res,"GetVersionAPI");
	}
	 
	
	// Returns version of current device driver. (XI_PRM_DRV_VERSION)
	void xiAPIplus_Camera::GetVersionDriver(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetVersionDriver");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_DRV_VERSION, buffer, buffer_length);
		CheckResult(res,"GetVersionDriver");
	}
	 
	
	// Returns version of MCU1 firmware. (XI_PRM_MCU1_VERSION)
	void xiAPIplus_Camera::GetVersionMCU1(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetVersionMCU1");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_MCU1_VERSION, buffer, buffer_length);
		CheckResult(res,"GetVersionMCU1");
	}
	 
	
	// Returns version of MCU2 firmware. (XI_PRM_MCU2_VERSION)
	void xiAPIplus_Camera::GetVersionMCU2(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetVersionMCU2");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_MCU2_VERSION, buffer, buffer_length);
		CheckResult(res,"GetVersionMCU2");
	}
	 
	
	// Returns version of MCU3 firmware. (XI_PRM_MCU3_VERSION)
	void xiAPIplus_Camera::GetVersionMCU3(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetVersionMCU3");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_MCU3_VERSION, buffer, buffer_length);
		CheckResult(res,"GetVersionMCU3");
	}
	 
	
	// Returns version of FPGA firmware currently running. (XI_PRM_FPGA1_VERSION)
	void xiAPIplus_Camera::GetVersionFPGA1(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetVersionFPGA1");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_FPGA1_VERSION, buffer, buffer_length);
		CheckResult(res,"GetVersionFPGA1");
	}
	 
	
	// Returns version of XML manifest. (XI_PRM_XMLMAN_VERSION)
	void xiAPIplus_Camera::GetVersionXMLMAN(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetVersionXMLMAN");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_XMLMAN_VERSION, buffer, buffer_length);
		CheckResult(res,"GetVersionXMLMAN");
	}
	 
	
	// Returns hardware revision number. (XI_PRM_HW_REVISION)
	void xiAPIplus_Camera::GetHWRevision(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetHWRevision");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_HW_REVISION, buffer, buffer_length);
		CheckResult(res,"GetHWRevision");
	}
	 
	
	// Returns version of factory set. (XI_PRM_FACTORY_SET_VERSION)
	void xiAPIplus_Camera::GetVersionFactSet(char* buffer, int buffer_length)
	{
		
		CheckCamHandle("GetVersionFactSet");
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_FACTORY_SET_VERSION, buffer, buffer_length);
		CheckResult(res,"GetVersionFactSet");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: API features
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Set debug level (XI_PRM_DEBUG_LEVEL)
	XI_DEBUG_LEVEL xiAPIplus_Camera::GetDebugLevel()
	{
		int val=0;
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBUG_LEVEL, &val);
		CheckResult(res,"GetDebugLevel");
		return (XI_DEBUG_LEVEL)val;
	}
	
	XI_DEBUG_LEVEL xiAPIplus_Camera::GetDebugLevel_Maximum()
	{
		int val=0;
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBUG_LEVEL XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDebugLevel" "_Maximum");
		return (XI_DEBUG_LEVEL)val;
	}
	
	XI_DEBUG_LEVEL xiAPIplus_Camera::GetDebugLevel_Minimum()
	{
		int val=0;
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBUG_LEVEL XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDebugLevel" "_Minimum");
		return (XI_DEBUG_LEVEL)val;
	}
	
	int xiAPIplus_Camera::GetDebugLevel_Increment()
	{
		int val=0;
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DEBUG_LEVEL XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDebugLevel" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetDebugLevel(XI_DEBUG_LEVEL DebugLevel)
	{
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DEBUG_LEVEL, DebugLevel);
		CheckResult(res,"SetDebugLevel");
	}
	 
	
	// Automatic bandwidth calculation, (XI_PRM_AUTO_BANDWIDTH_CALCULATION)
	bool xiAPIplus_Camera::IsAutoBandwidthCalculation()
	{
		int val=0;
		
		xiGetParamInt(camera_handle, XI_PRM_AUTO_BANDWIDTH_CALCULATION, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableAutoBandwidthCalculation()
	{
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_AUTO_BANDWIDTH_CALCULATION, XI_ON);
		CheckResult(res,"EnableAutoBandwidthCalculation");
	}

	void xiAPIplus_Camera::DisableAutoBandwidthCalculation()
	{
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_AUTO_BANDWIDTH_CALCULATION, XI_OFF);
		CheckResult(res,"DisableAutoBandwidthCalculation");
	}	
	 
	
	// Enables (2015/FAPI) processing chain for MQ MU cameras. If disabled - legacy processing 2006 is used. (XI_PRM_NEW_PROCESS_CHAIN_ENABLE)
	bool xiAPIplus_Camera::IsNewProcessChainEnable()
	{
		int val=0;
		
		xiGetParamInt(camera_handle, XI_PRM_NEW_PROCESS_CHAIN_ENABLE, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableNewProcessChainEnable()
	{
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_NEW_PROCESS_CHAIN_ENABLE, XI_ON);
		CheckResult(res,"EnableNewProcessChainEnable");
	}

	void xiAPIplus_Camera::DisableNewProcessChainEnable()
	{
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_NEW_PROCESS_CHAIN_ENABLE, XI_OFF);
		CheckResult(res,"DisableNewProcessChainEnable");
	}	
	 
	
	// Number of threads per image processor (XI_PRM_PROC_NUM_THREADS)
	// integer type
	int xiAPIplus_Camera::GetProcessorNumberThreads()
	{
		
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_PROC_NUM_THREADS, &val);
		CheckResult(res,"GetProcessorNumberThreads");
		return val;	
	}
	int xiAPIplus_Camera::GetProcessorNumberThreads_Maximum()
	{		
		
		int val=0;
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_PROC_NUM_THREADS XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetProcessorNumberThreads" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetProcessorNumberThreads_Minimum()
	{
		
		int val=0;
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_PROC_NUM_THREADS XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetProcessorNumberThreads" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetProcessorNumberThreads_Increment()
	{
		
		int val=0;
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_PROC_NUM_THREADS XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetProcessorNumberThreads" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetProcessorNumberThreads(int ProcessorNumberThreads)
	{
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_PROC_NUM_THREADS, ProcessorNumberThreads);
		CheckResult(res,"SetProcessorNumberThreads");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Camera FFS
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Read file from camera flash filesystem. (XI_PRM_READ_FILE_FFS)
	void xiAPIplus_Camera::GetReadFileFFS(char* buffer, int buffer_length)
	{
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_READ_FILE_FFS, buffer, buffer_length);
		CheckResult(res,"GetReadFileFFS");
	}
	 
	
	// Write file to camera flash filesystem. (XI_PRM_WRITE_FILE_FFS)
	void xiAPIplus_Camera::GetWriteFileFFS(char* buffer, int buffer_length)
	{
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_WRITE_FILE_FFS, buffer, buffer_length);
		CheckResult(res,"GetWriteFileFFS");
	}
	
	void xiAPIplus_Camera::SetWriteFileFFS(char* new_value)
	{
		
		XI_RETURN res=xiSetParamString(camera_handle, XI_PRM_WRITE_FILE_FFS, new_value, (DWORD)strlen(new_value));
		CheckResult(res,"SetWriteFileFFS");
	}
	 
	
	// Set name of file to be written/read from camera FFS. (XI_PRM_FFS_FILE_NAME)
	void xiAPIplus_Camera::GetFFSFileName(char* buffer, int buffer_length)
	{
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_FFS_FILE_NAME, buffer, buffer_length);
		CheckResult(res,"GetFFSFileName");
	}
	
	void xiAPIplus_Camera::SetFFSFileName(char* new_value)
	{
		
		XI_RETURN res=xiSetParamString(camera_handle, XI_PRM_FFS_FILE_NAME, new_value, (DWORD)strlen(new_value));
		CheckResult(res,"SetFFSFileName");
	}
	 
	
	// File number. (XI_PRM_FFS_FILE_ID)
	// integer type
	int xiAPIplus_Camera::GetFFSFileId()
	{
		
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_FFS_FILE_ID, &val);
		CheckResult(res,"GetFFSFileId");
		return val;	
	}
	int xiAPIplus_Camera::GetFFSFileId_Maximum()
	{		
		
		int val=0;
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_FFS_FILE_ID XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetFFSFileId" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetFFSFileId_Minimum()
	{
		
		int val=0;
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_FFS_FILE_ID XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetFFSFileId" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetFFSFileId_Increment()
	{
		
		int val=0;
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_FFS_FILE_ID XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetFFSFileId" "_Increment");
		return val;		
	}
	 
	
	// Size of file. (XI_PRM_FFS_FILE_SIZE)
	// integer type
	int xiAPIplus_Camera::GetFFSFileSize()
	{
		
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_FFS_FILE_SIZE, &val);
		CheckResult(res,"GetFFSFileSize");
		return val;	
	}
	int xiAPIplus_Camera::GetFFSFileSize_Maximum()
	{		
		
		int val=0;
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_FFS_FILE_SIZE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetFFSFileSize" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetFFSFileSize_Minimum()
	{
		
		int val=0;
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_FFS_FILE_SIZE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetFFSFileSize" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetFFSFileSize_Increment()
	{
		
		int val=0;
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_FFS_FILE_SIZE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetFFSFileSize" "_Increment");
		return val;		
	}
	 
	
	// Size of free camera FFS. (XI_PRM_FREE_FFS_SIZE)
	// integer type
	uint64_t xiAPIplus_Camera::GetFreeFFSSize()
	{
		
		uint64_t val=0;
		DWORD size = sizeof(val);
		XI_PRM_TYPE type = xiTypeInteger64;		
		XI_RETURN res=xiGetParam(camera_handle, XI_PRM_FREE_FFS_SIZE, &val, &size, &type);
		CheckResult(res,"GetFreeFFSSize");
		return val;	
	}
	uint64_t xiAPIplus_Camera::GetFreeFFSSize_Maximum()
	{		
		
		uint64_t val=0;
		DWORD size = sizeof(val);
		XI_PRM_TYPE type = xiTypeInteger64;
		XI_RETURN res=xiGetParam(camera_handle, XI_PRM_FREE_FFS_SIZE XI_PRM_INFO_MAX, &val, &size, &type);
		CheckResult(res,"GetFreeFFSSize" "_Maximum");
		return val;
	}
	
	uint64_t xiAPIplus_Camera::GetFreeFFSSize_Minimum()
	{
		
		uint64_t val=0;
		DWORD size = sizeof(val);
		XI_PRM_TYPE type = xiTypeInteger64;
		XI_RETURN res=xiGetParam(camera_handle, XI_PRM_FREE_FFS_SIZE XI_PRM_INFO_MIN, &val, &size, &type);
		CheckResult(res,"GetFreeFFSSize" "_Minimum");
		return val;
	}

	uint64_t xiAPIplus_Camera::GetFreeFFSSize_Increment()
	{
		
		uint64_t val=0;
		DWORD size = sizeof(val);
		XI_PRM_TYPE type = xiTypeInteger64;
		XI_RETURN res=xiGetParam(camera_handle, XI_PRM_FREE_FFS_SIZE XI_PRM_INFO_INCREMENT, &val, &size, &type);
		CheckResult(res,"GetFreeFFSSize" "_Increment");
		return val;		
	}
	 
	
	// Size of used camera FFS. (XI_PRM_USED_FFS_SIZE)
	// integer type
	uint64_t xiAPIplus_Camera::GetUsedFFSSize()
	{
		
		uint64_t val=0;
		DWORD size = sizeof(val);
		XI_PRM_TYPE type = xiTypeInteger64;		
		XI_RETURN res=xiGetParam(camera_handle, XI_PRM_USED_FFS_SIZE, &val, &size, &type);
		CheckResult(res,"GetUsedFFSSize");
		return val;	
	}
	uint64_t xiAPIplus_Camera::GetUsedFFSSize_Maximum()
	{		
		
		uint64_t val=0;
		DWORD size = sizeof(val);
		XI_PRM_TYPE type = xiTypeInteger64;
		XI_RETURN res=xiGetParam(camera_handle, XI_PRM_USED_FFS_SIZE XI_PRM_INFO_MAX, &val, &size, &type);
		CheckResult(res,"GetUsedFFSSize" "_Maximum");
		return val;
	}
	
	uint64_t xiAPIplus_Camera::GetUsedFFSSize_Minimum()
	{
		
		uint64_t val=0;
		DWORD size = sizeof(val);
		XI_PRM_TYPE type = xiTypeInteger64;
		XI_RETURN res=xiGetParam(camera_handle, XI_PRM_USED_FFS_SIZE XI_PRM_INFO_MIN, &val, &size, &type);
		CheckResult(res,"GetUsedFFSSize" "_Minimum");
		return val;
	}

	uint64_t xiAPIplus_Camera::GetUsedFFSSize_Increment()
	{
		
		uint64_t val=0;
		DWORD size = sizeof(val);
		XI_PRM_TYPE type = xiTypeInteger64;
		XI_RETURN res=xiGetParam(camera_handle, XI_PRM_USED_FFS_SIZE XI_PRM_INFO_INCREMENT, &val, &size, &type);
		CheckResult(res,"GetUsedFFSSize" "_Increment");
		return val;		
	}
	 
	
	// Setting of key enables file operations on some cameras. (XI_PRM_FFS_ACCESS_KEY)
	// integer type
	int xiAPIplus_Camera::GetFFSAccessKey()
	{
		CheckCamHandle("GetFFSAccessKey");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_FFS_ACCESS_KEY, &val);
		CheckResult(res,"GetFFSAccessKey");
		return val;	
	}
	int xiAPIplus_Camera::GetFFSAccessKey_Maximum()
	{		
		CheckCamHandle("GetFFSAccessKey" "_Maximum");
		int val=0;
		CheckCamHandle("GetFFSAccessKey");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_FFS_ACCESS_KEY XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetFFSAccessKey" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetFFSAccessKey_Minimum()
	{
		CheckCamHandle("GetFFSAccessKey" "_Minimum");
		int val=0;
		CheckCamHandle("GetFFSAccessKey");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_FFS_ACCESS_KEY XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetFFSAccessKey" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetFFSAccessKey_Increment()
	{
		CheckCamHandle("GetFFSAccessKey" "_Increment");
		int val=0;
		CheckCamHandle("GetFFSAccessKey");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_FFS_ACCESS_KEY XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetFFSAccessKey" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetFFSAccessKey(int FFSAccessKey)
	{
		
		CheckCamHandleInt("SetFFSAccessKey",FFSAccessKey);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_FFS_ACCESS_KEY, FFSAccessKey);
		CheckResult(res,"SetFFSAccessKey");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: APIContextControl
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// List of current parameters settings context - parameters with values. Used for offline processing. (XI_PRM_API_CONTEXT_LIST)
	void xiAPIplus_Camera::GetApiContextList(char* buffer, int buffer_length)
	{
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_API_CONTEXT_LIST, buffer, buffer_length);
		CheckResult(res,"GetApiContextList");
	}
	
	void xiAPIplus_Camera::SetApiContextList(char* new_value)
	{
		
		XI_RETURN res=xiSetParamString(camera_handle, XI_PRM_API_CONTEXT_LIST, new_value, (DWORD)strlen(new_value));
		CheckResult(res,"SetApiContextList");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Sensor Control
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Selects the current feature which is accessible by XI_PRM_SENSOR_FEATURE_VALUE. (XI_PRM_SENSOR_FEATURE_SELECTOR)
	XI_SENSOR_FEATURE_SELECTOR xiAPIplus_Camera::GetSensorFeatureSelector()
	{
		int val=0;
		
		CheckCamHandle("GetSensorFeatureSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_FEATURE_SELECTOR, &val);
		CheckResult(res,"GetSensorFeatureSelector");
		return (XI_SENSOR_FEATURE_SELECTOR)val;
	}
	
	XI_SENSOR_FEATURE_SELECTOR xiAPIplus_Camera::GetSensorFeatureSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetSensorFeatureSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_FEATURE_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetSensorFeatureSelector" "_Maximum");
		return (XI_SENSOR_FEATURE_SELECTOR)val;
	}
	
	XI_SENSOR_FEATURE_SELECTOR xiAPIplus_Camera::GetSensorFeatureSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetSensorFeatureSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_FEATURE_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetSensorFeatureSelector" "_Minimum");
		return (XI_SENSOR_FEATURE_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetSensorFeatureSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetSensorFeatureSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_FEATURE_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetSensorFeatureSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetSensorFeatureSelector(XI_SENSOR_FEATURE_SELECTOR SensorFeatureSelector)
	{
		
		CheckCamHandleInt("SetSensorFeatureSelector",(int)SensorFeatureSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_SENSOR_FEATURE_SELECTOR, SensorFeatureSelector);
		CheckResult(res,"SetSensorFeatureSelector");
	}
	 
	
	// Allows access to sensor feature value currently selected by XI_PRM_SENSOR_FEATURE_SELECTOR. (XI_PRM_SENSOR_FEATURE_VALUE)
	// integer type
	int xiAPIplus_Camera::GetSensorFeatureValue()
	{
		CheckCamHandle("GetSensorFeatureValue");
		int val=0;
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_FEATURE_VALUE, &val);
		CheckResult(res,"GetSensorFeatureValue");
		return val;	
	}
	int xiAPIplus_Camera::GetSensorFeatureValue_Maximum()
	{		
		CheckCamHandle("GetSensorFeatureValue" "_Maximum");
		int val=0;
		CheckCamHandle("GetSensorFeatureValue");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_FEATURE_VALUE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetSensorFeatureValue" "_Maximum");
		return val;
	}
	
	int xiAPIplus_Camera::GetSensorFeatureValue_Minimum()
	{
		CheckCamHandle("GetSensorFeatureValue" "_Minimum");
		int val=0;
		CheckCamHandle("GetSensorFeatureValue");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_FEATURE_VALUE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetSensorFeatureValue" "_Minimum");
		return val;
	}

	int xiAPIplus_Camera::GetSensorFeatureValue_Increment()
	{
		CheckCamHandle("GetSensorFeatureValue" "_Increment");
		int val=0;
		CheckCamHandle("GetSensorFeatureValue");
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_SENSOR_FEATURE_VALUE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetSensorFeatureValue" "_Increment");
		return val;		
	}
	
	void xiAPIplus_Camera::SetSensorFeatureValue(int SensorFeatureValue)
	{
		
		CheckCamHandleInt("SetSensorFeatureValue",SensorFeatureValue);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_SENSOR_FEATURE_VALUE, SensorFeatureValue);
		CheckResult(res,"SetSensorFeatureValue");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: Extended Features
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Selects the internal acquisition signal to read using XI_PRM_ACQUISITION_STATUS. (XI_PRM_ACQUISITION_STATUS_SELECTOR)
	XI_ACQUISITION_STATUS_SELECTOR xiAPIplus_Camera::GetAcquisitionStatusSelector()
	{
		int val=0;
		
		CheckCamHandle("GetAcquisitionStatusSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQUISITION_STATUS_SELECTOR, &val);
		CheckResult(res,"GetAcquisitionStatusSelector");
		return (XI_ACQUISITION_STATUS_SELECTOR)val;
	}
	
	XI_ACQUISITION_STATUS_SELECTOR xiAPIplus_Camera::GetAcquisitionStatusSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetAcquisitionStatusSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQUISITION_STATUS_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAcquisitionStatusSelector" "_Maximum");
		return (XI_ACQUISITION_STATUS_SELECTOR)val;
	}
	
	XI_ACQUISITION_STATUS_SELECTOR xiAPIplus_Camera::GetAcquisitionStatusSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetAcquisitionStatusSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQUISITION_STATUS_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAcquisitionStatusSelector" "_Minimum");
		return (XI_ACQUISITION_STATUS_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetAcquisitionStatusSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetAcquisitionStatusSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQUISITION_STATUS_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAcquisitionStatusSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetAcquisitionStatusSelector(XI_ACQUISITION_STATUS_SELECTOR AcquisitionStatusSelector)
	{
		
		CheckCamHandleInt("SetAcquisitionStatusSelector",(int)AcquisitionStatusSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_ACQUISITION_STATUS_SELECTOR, AcquisitionStatusSelector);
		CheckResult(res,"SetAcquisitionStatusSelector");
	}
	 
	
	// Acquisition status(True/False) (XI_PRM_ACQUISITION_STATUS)
	XI_SWITCH xiAPIplus_Camera::GetAcquisitionStatus()
	{
		int val=0;
		
		CheckCamHandle("GetAcquisitionStatus");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQUISITION_STATUS, &val);
		CheckResult(res,"GetAcquisitionStatus");
		return (XI_SWITCH)val;
	}
	
	XI_SWITCH xiAPIplus_Camera::GetAcquisitionStatus_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetAcquisitionStatus" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQUISITION_STATUS XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetAcquisitionStatus" "_Maximum");
		return (XI_SWITCH)val;
	}
	
	XI_SWITCH xiAPIplus_Camera::GetAcquisitionStatus_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetAcquisitionStatus" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQUISITION_STATUS XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetAcquisitionStatus" "_Minimum");
		return (XI_SWITCH)val;
	}
	
	int xiAPIplus_Camera::GetAcquisitionStatus_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetAcquisitionStatus" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_ACQUISITION_STATUS XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetAcquisitionStatus" "_Increment");
		return val;
	}
	 
	
	// Data Pipe Unit Selector. (XI_PRM_DP_UNIT_SELECTOR)
	XI_DP_UNIT_SELECTOR xiAPIplus_Camera::GetDataPipeUnitSelector()
	{
		int val=0;
		
		CheckCamHandle("GetDataPipeUnitSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DP_UNIT_SELECTOR, &val);
		CheckResult(res,"GetDataPipeUnitSelector");
		return (XI_DP_UNIT_SELECTOR)val;
	}
	
	XI_DP_UNIT_SELECTOR xiAPIplus_Camera::GetDataPipeUnitSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetDataPipeUnitSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DP_UNIT_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDataPipeUnitSelector" "_Maximum");
		return (XI_DP_UNIT_SELECTOR)val;
	}
	
	XI_DP_UNIT_SELECTOR xiAPIplus_Camera::GetDataPipeUnitSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetDataPipeUnitSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DP_UNIT_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDataPipeUnitSelector" "_Minimum");
		return (XI_DP_UNIT_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetDataPipeUnitSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetDataPipeUnitSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DP_UNIT_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDataPipeUnitSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetDataPipeUnitSelector(XI_DP_UNIT_SELECTOR DataPipeUnitSelector)
	{
		
		CheckCamHandleInt("SetDataPipeUnitSelector",(int)DataPipeUnitSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DP_UNIT_SELECTOR, DataPipeUnitSelector);
		CheckResult(res,"SetDataPipeUnitSelector");
	}
	 
	
	// Data Pipe Processor Selector. (XI_PRM_DP_PROC_SELECTOR)
	XI_DP_PROC_SELECTOR xiAPIplus_Camera::GetDataPipeProcSelector()
	{
		int val=0;
		
		CheckCamHandle("GetDataPipeProcSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DP_PROC_SELECTOR, &val);
		CheckResult(res,"GetDataPipeProcSelector");
		return (XI_DP_PROC_SELECTOR)val;
	}
	
	XI_DP_PROC_SELECTOR xiAPIplus_Camera::GetDataPipeProcSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetDataPipeProcSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DP_PROC_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDataPipeProcSelector" "_Maximum");
		return (XI_DP_PROC_SELECTOR)val;
	}
	
	XI_DP_PROC_SELECTOR xiAPIplus_Camera::GetDataPipeProcSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetDataPipeProcSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DP_PROC_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDataPipeProcSelector" "_Minimum");
		return (XI_DP_PROC_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetDataPipeProcSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetDataPipeProcSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DP_PROC_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDataPipeProcSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetDataPipeProcSelector(XI_DP_PROC_SELECTOR DataPipeProcSelector)
	{
		
		CheckCamHandleInt("SetDataPipeProcSelector",(int)DataPipeProcSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DP_PROC_SELECTOR, DataPipeProcSelector);
		CheckResult(res,"SetDataPipeProcSelector");
	}
	 
	
	// Data Pipe Processor parameter Selector. (XI_PRM_DP_PARAM_SELECTOR)
	XI_DP_PARAM_SELECTOR xiAPIplus_Camera::GetDataPipeParamSelector()
	{
		int val=0;
		
		CheckCamHandle("GetDataPipeParamSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DP_PARAM_SELECTOR, &val);
		CheckResult(res,"GetDataPipeParamSelector");
		return (XI_DP_PARAM_SELECTOR)val;
	}
	
	XI_DP_PARAM_SELECTOR xiAPIplus_Camera::GetDataPipeParamSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetDataPipeParamSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DP_PARAM_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDataPipeParamSelector" "_Maximum");
		return (XI_DP_PARAM_SELECTOR)val;
	}
	
	XI_DP_PARAM_SELECTOR xiAPIplus_Camera::GetDataPipeParamSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetDataPipeParamSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DP_PARAM_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDataPipeParamSelector" "_Minimum");
		return (XI_DP_PARAM_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetDataPipeParamSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetDataPipeParamSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_DP_PARAM_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDataPipeParamSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetDataPipeParamSelector(XI_DP_PARAM_SELECTOR DataPipeParamSelector)
	{
		
		CheckCamHandleInt("SetDataPipeParamSelector",(int)DataPipeParamSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_DP_PARAM_SELECTOR, DataPipeParamSelector);
		CheckResult(res,"SetDataPipeParamSelector");
	}
	 
	
	// Data Pipe processor parameter value (XI_PRM_DP_PARAM_VALUE)
	float xiAPIplus_Camera::GetDataPipeParamValue()
	{
		float val=0;
		
		CheckCamHandle("GetDataPipeParamValue");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_DP_PARAM_VALUE, &val);
		CheckResult(res,"GetDataPipeParamValue");
		return val;
	}

	float xiAPIplus_Camera::GetDataPipeParamValue_Maximum()
	{
		float val=0;
		
		CheckCamHandle("GetDataPipeParamValue" "_Maximum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_DP_PARAM_VALUE XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetDataPipeParamValue" "_Maximum");
		return val;
	}

	float xiAPIplus_Camera::GetDataPipeParamValue_Minimum()
	{
		float val=0;
		
		CheckCamHandle("GetDataPipeParamValue" "_Minimum");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_DP_PARAM_VALUE XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetDataPipeParamValue" "_Minimum");
		return val;
	}

	float xiAPIplus_Camera::GetDataPipeParamValue_Increment()
	{
		float val=0;
		
		CheckCamHandle("GetDataPipeParamValue" "_Increment");
		
		XI_RETURN res=xiGetParamFloat(camera_handle, XI_PRM_DP_PARAM_VALUE XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetDataPipeParamValue" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetDataPipeParamValue(float DataPipeParamValue)
	{
		
		CheckCamHandle("SetDataPipeParamValue");
		
		XI_RETURN res=xiSetParamFloat(camera_handle, XI_PRM_DP_PARAM_VALUE, DataPipeParamValue);
		CheckResult(res,"SetDataPipeParamValue");
	}
	 
	
	// Enable or disable low level streaming via GenTL. (XI_PRM_GENTL_DATASTREAM_ENABLED)
	bool xiAPIplus_Camera::IsGenTLStreamEn()
	{
		int val=0;
		
		xiGetParamInt(camera_handle, XI_PRM_GENTL_DATASTREAM_ENABLED, &val);
		return (val!=0);
	}
	
	void xiAPIplus_Camera::EnableGenTLStreamEn()
	{
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_GENTL_DATASTREAM_ENABLED, XI_ON);
		CheckResult(res,"EnableGenTLStreamEn");
	}

	void xiAPIplus_Camera::DisableGenTLStreamEn()
	{
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_GENTL_DATASTREAM_ENABLED, XI_OFF);
		CheckResult(res,"DisableGenTLStreamEn");
	}	
	 
	
	// Get GenTL stream context pointer for low level streaming (XI_PRM_GENTL_DATASTREAM_CONTEXT)
	void xiAPIplus_Camera::GetGenTLStreamContext(char* buffer, int buffer_length)
	{
		
		XI_RETURN res=xiGetParamString(camera_handle, XI_PRM_GENTL_DATASTREAM_CONTEXT, buffer, buffer_length);
		CheckResult(res,"GetGenTLStreamContext");
	}
	

	//-------------------------------------------------------------------------------------------------------------------
	// ---- Parameter Group: User Set Control
	//-------------------------------------------------------------------------------------------------------------------

	 
	
	// Selects the feature User Set to load, save or configure. (XI_PRM_USER_SET_SELECTOR)
	XI_USER_SET_SELECTOR xiAPIplus_Camera::GetUserSetSelector()
	{
		int val=0;
		
		CheckCamHandle("GetUserSetSelector");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_USER_SET_SELECTOR, &val);
		CheckResult(res,"GetUserSetSelector");
		return (XI_USER_SET_SELECTOR)val;
	}
	
	XI_USER_SET_SELECTOR xiAPIplus_Camera::GetUserSetSelector_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetUserSetSelector" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_USER_SET_SELECTOR XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetUserSetSelector" "_Maximum");
		return (XI_USER_SET_SELECTOR)val;
	}
	
	XI_USER_SET_SELECTOR xiAPIplus_Camera::GetUserSetSelector_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetUserSetSelector" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_USER_SET_SELECTOR XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetUserSetSelector" "_Minimum");
		return (XI_USER_SET_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetUserSetSelector_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetUserSetSelector" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_USER_SET_SELECTOR XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetUserSetSelector" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetUserSetSelector(XI_USER_SET_SELECTOR UserSetSelector)
	{
		
		CheckCamHandleInt("SetUserSetSelector",(int)UserSetSelector);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_USER_SET_SELECTOR, UserSetSelector);
		CheckResult(res,"SetUserSetSelector");
	}
	 
	
	// Loads the User Set specified by User Set Selector to the device and makes it active. (XI_PRM_USER_SET_LOAD)
	void xiAPIplus_Camera::SetUserSetLoad(int UserSetLoad)
	{
		
		CheckCamHandleInt("SetUserSetLoad",UserSetLoad);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_USER_SET_LOAD, UserSetLoad);
		CheckResult(res,"SetUserSetLoad");
	}
	 
	
	// Selects the feature User Set to load and make active by default when the device is reset. Change might affect default mode in other applications, e.g. CamTool. (XI_PRM_USER_SET_DEFAULT)
	XI_USER_SET_SELECTOR xiAPIplus_Camera::GetUserSetDefault()
	{
		int val=0;
		
		CheckCamHandle("GetUserSetDefault");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_USER_SET_DEFAULT, &val);
		CheckResult(res,"GetUserSetDefault");
		return (XI_USER_SET_SELECTOR)val;
	}
	
	XI_USER_SET_SELECTOR xiAPIplus_Camera::GetUserSetDefault_Maximum()
	{
		int val=0;
		
		CheckCamHandle("GetUserSetDefault" "_Maximum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_USER_SET_DEFAULT XI_PRM_INFO_MAX, &val);
		CheckResult(res,"GetUserSetDefault" "_Maximum");
		return (XI_USER_SET_SELECTOR)val;
	}
	
	XI_USER_SET_SELECTOR xiAPIplus_Camera::GetUserSetDefault_Minimum()
	{
		int val=0;
		
		CheckCamHandle("GetUserSetDefault" "_Minimum");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_USER_SET_DEFAULT XI_PRM_INFO_MIN, &val);
		CheckResult(res,"GetUserSetDefault" "_Minimum");
		return (XI_USER_SET_SELECTOR)val;
	}
	
	int xiAPIplus_Camera::GetUserSetDefault_Increment()
	{
		int val=0;
		
		CheckCamHandle("GetUserSetDefault" "_Increment");
		
		XI_RETURN res=xiGetParamInt(camera_handle, XI_PRM_USER_SET_DEFAULT XI_PRM_INFO_INCREMENT, &val);
		CheckResult(res,"GetUserSetDefault" "_Increment");
		return val;
	}
	
	void xiAPIplus_Camera::SetUserSetDefault(XI_USER_SET_SELECTOR UserSetDefault)
	{
		
		CheckCamHandleInt("SetUserSetDefault",(int)UserSetDefault);
		
		XI_RETURN res=xiSetParamInt(camera_handle, XI_PRM_USER_SET_DEFAULT, UserSetDefault);
		CheckResult(res,"SetUserSetDefault");
	}
	


//-------------------------------------------------------------------------------------------------------------------
// Error codes xiApi
struct xiapi_errorcode_t
{
	XI_RETURN code;
	const char*     descr;
};

xiapi_errorcode_t xiAPIplus_errorcodes_list[]=
{
	XI_OK                             ,  "Function call succeeded",
		XI_INVALID_HANDLE                 ,  "Invalid handle",
		XI_READREG                        ,  "Register read error",
		XI_WRITEREG                       ,  "Register write error",
		XI_FREE_RESOURCES                 ,  "Freeing resources error",
		XI_FREE_CHANNEL                   ,  "Freeing channel error",
		XI_FREE_BANDWIDTH                 ,  "Freeing bandwith error",
		XI_READBLK                        ,  "Read block error",
		XI_WRITEBLK                       ,  "Write block error",
		XI_NO_IMAGE                       ,  "No image",
		XI_TIMEOUT                        ,  "Timeout",
		XI_INVALID_ARG                    ,  "Invalid arguments supplied",
		XI_NOT_SUPPORTED                  ,  "Not supported",
		XI_ISOCH_ATTACH_BUFFERS           ,  "Attach buffers error",
		XI_GET_OVERLAPPED_RESULT          ,  "Overlapped result",
		XI_MEMORY_ALLOCATION              ,  "Memory allocation error",
		XI_DLLCONTEXTISNULL               ,  "DLL context is NULL",
		XI_DLLCONTEXTISNONZERO            ,  "DLL context is non zero",
		XI_DLLCONTEXTEXIST                ,  "DLL context exists",
		XI_TOOMANYDEVICES                 ,  "Too many devices connected",
		XI_ERRORCAMCONTEXT                ,  "Camera context error",
		XI_UNKNOWN_HARDWARE               ,  "Unknown hardware",
		XI_INVALID_TM_FILE                ,  "Invalid TM file",
		XI_INVALID_TM_TAG                 ,  "Invalid TM tag",
		XI_INCOMPLETE_TM                  ,  "Incomplete TM",
		XI_BUS_RESET_FAILED               ,  "Bus reset error",
		XI_NOT_IMPLEMENTED                ,  "Not implemented",
		XI_SHADING_TOOBRIGHT              ,  "Shading is too bright",
		XI_SHADING_TOODARK                ,  "Shading is too dark",
		XI_TOO_LOW_GAIN                   ,  "Gain is too low",
		XI_INVALID_BPL                    ,  "Invalid sensor defect correction list",
		XI_BPL_REALLOC                    ,  "Error while sensor defect correction list reallocation",
		XI_INVALID_PIXEL_LIST             ,  "Invalid pixel list",
		XI_INVALID_FFS                    ,  "Invalid Flash File System",
		XI_INVALID_PROFILE                ,  "Invalid profile",
		XI_INVALID_CALIBRATION            ,  "Invalid calibration",
		XI_INVALID_BUFFER                 ,  "Invalid buffer",
		XI_INVALID_DATA                   ,  "Invalid data",
		XI_TGBUSY                         ,  "Timing generator is busy",
		XI_IO_WRONG                       ,  "Wrong operation open/write/read/close",
		XI_ACQUISITION_ALREADY_UP         ,  "Acquisition already started",
		XI_OLD_DRIVER_VERSION             ,  "Old version of device driver installed to the system.",
		XI_GET_LAST_ERROR                 ,  "To get error code please call GetLastError function.",
		XI_CANT_PROCESS                   ,  "Data cannot be processed",
		XI_ACQUISITION_STOPED             ,  "Acquisition is stopped. It needs to be started to perform operation.",
		XI_ACQUISITION_STOPED_WERR        ,  "Acquisition has been stopped with an error.",
		XI_INVALID_INPUT_ICC_PROFILE      ,  "Input ICC profile missing or corrupted",
		XI_INVALID_OUTPUT_ICC_PROFILE     ,  "Output ICC profile missing or corrupted",
		XI_DEVICE_NOT_READY               ,  "Device not ready to operate",
		XI_SHADING_TOOCONTRAST            ,  "Shading is too contrast",
		XI_ALREADY_INITIALIZED            ,  "Module already initialized",
		XI_NOT_ENOUGH_PRIVILEGES          ,  "Application does not have enough privileges (one or more app)",
		XI_NOT_COMPATIBLE_DRIVER          ,  "Installed driver is not compatible with current software",
		XI_TM_INVALID_RESOURCE            ,  "TM file was not loaded successfully from resources",
		XI_DEVICE_HAS_BEEN_RESETED        ,  "Device has been reset, abnormal initial state",
		XI_NO_DEVICES_FOUND               ,  "No Devices Found",
		XI_RESOURCE_OR_FUNCTION_LOCKED    ,  "Resource (device) or function locked by mutex",
		XI_BUFFER_SIZE_TOO_SMALL          ,  "Buffer provided by user is too small",
		XI_COULDNT_INIT_PROCESSOR         ,  "Could not initialize processor.",
		XI_NOT_INITIALIZED                ,  "The object/module/procedure/process being referred to has not been started.",
		XI_RESOURCE_NOT_FOUND             ,  "Resource not found(could be processor, file, item...).",
		XI_UNKNOWN_PARAM                  ,  "Unknown parameter",
		XI_WRONG_PARAM_VALUE              ,  "Wrong parameter value",
		XI_WRONG_PARAM_TYPE               ,  "Wrong parameter type",
		XI_WRONG_PARAM_SIZE               ,  "Wrong parameter size",
		XI_BUFFER_TOO_SMALL               ,  "Input buffer is too small",
		XI_NOT_SUPPORTED_PARAM            ,  "Parameter is not supported",
		XI_NOT_SUPPORTED_PARAM_INFO       ,  "Parameter info not supported",
		XI_NOT_SUPPORTED_DATA_FORMAT      ,  "Data format is not supported",
		XI_READ_ONLY_PARAM                ,  "Read only parameter",
		XI_BANDWIDTH_NOT_SUPPORTED        ,  "This camera does not support currently available bandwidth",
		XI_INVALID_FFS_FILE_NAME          ,  "FFS file selector is invalid or NULL",
		XI_FFS_FILE_NOT_FOUND             ,  "FFS file not found",
		XI_PARAM_NOT_SETTABLE             ,  "Parameter value cannot be set (might be out of range or invalid).",
		XI_SAFE_POLICY_NOT_SUPPORTED      ,  "Safe buffer policy is not supported. E.g. when transport target is set to GPU (GPUDirect).",
		XI_GPUDIRECT_NOT_AVAILABLE        ,  "GPUDirect is not available. E.g. platform isn't supported or CUDA toolkit isn't installed.",
		XI_INCORRECT_SENS_ID_CHECK        ,  "Incorrect sensor board unique identifier checksum.",
		XI_INCORRECT_FPGA_TYPE            ,  "Incorrect or unknown FPGA firmware type used for camera.",
		XI_PARAM_CONDITIONALLY_NOT_AVAILABLE,  "Parameter is not available in current context. Available only if another feature is turned on.",
		XI_PROC_OTHER_ERROR               ,  "Processing error - other",
		XI_PROC_PROCESSING_ERROR          ,  "Error while image processing.",
		XI_PROC_INPUT_FORMAT_UNSUPPORTED  ,  "Input format is not supported for processing.",
		XI_PROC_OUTPUT_FORMAT_UNSUPPORTED ,  "Output format is not supported for processing.",
		XI_OUT_OF_RANGE                   ,  "Parameter value is out of range",
		
};




xiAPIplus_Enumerators::xiAPIplus_Enumerators()
{
	Init();
}

void xiAPIplus_Enumerators::Init()
{

	// Downsampling value enumerator.
	XI_DOWNSAMPLING_VALUE_ITEMS.push_back({"XI_DWN_1x1",                             1, "1 sensor pixel = 1 image pixel"});
	XI_DOWNSAMPLING_VALUE_ITEMS.push_back({"XI_DWN_2x2",                             2, "2x2 sensor pixels = 1 image pixel"});
	XI_DOWNSAMPLING_VALUE_ITEMS.push_back({"XI_DWN_3x3",                             3, "Downsampling 3x3."});
	XI_DOWNSAMPLING_VALUE_ITEMS.push_back({"XI_DWN_4x4",                             4, "4x4 sensor pixels = 1 image pixel"});
	XI_DOWNSAMPLING_VALUE_ITEMS.push_back({"XI_DWN_5x5",                             5, "Downsampling 5x5."});
	XI_DOWNSAMPLING_VALUE_ITEMS.push_back({"XI_DWN_6x6",                             6, "Downsampling 6x6."});
	XI_DOWNSAMPLING_VALUE_ITEMS.push_back({"XI_DWN_7x7",                             7, "Downsampling 7x7."});
	XI_DOWNSAMPLING_VALUE_ITEMS.push_back({"XI_DWN_8x8",                             8, "Downsampling 8x8."});
	XI_DOWNSAMPLING_VALUE_ITEMS.push_back({"XI_DWN_9x9",                             9, "Downsampling 9x9."});
	XI_DOWNSAMPLING_VALUE_ITEMS.push_back({"XI_DWN_10x10",                           10, "Downsampling 10x10."});
	XI_DOWNSAMPLING_VALUE_ITEMS.push_back({"XI_DWN_16x16",                           16, "Downsampling 16x16."});

	// Test Pattern Generator
	XI_TEST_PATTERN_GENERATOR_ITEMS.push_back({"XI_TESTPAT_GEN_SENSOR",                  0, "Sensor test pattern generator"});
	XI_TEST_PATTERN_GENERATOR_ITEMS.push_back({"XI_TESTPAT_GEN_FPGA",                    1, " FPGA Test Pattern Generator"});

	// Module/Unit version selector
	XI_VERSION_ITEMS.push_back({"XI_VER_API",                             0, "version of API"});
	XI_VERSION_ITEMS.push_back({"XI_VER_DRV",                             1, "version of device driver"});
	XI_VERSION_ITEMS.push_back({"XI_VER_MCU1",                            2, "version of MCU1 firmware."});
	XI_VERSION_ITEMS.push_back({"XI_VER_MCU2",                            3, "version of MCU2 firmware."});
	XI_VERSION_ITEMS.push_back({"XI_VER_MCU3",                            4, "version of MCU3 firmware."});
	XI_VERSION_ITEMS.push_back({"XI_VER_FPGA1",                           5, "version of FPGA1 firmware."});
	XI_VERSION_ITEMS.push_back({"XI_VER_XMLMAN",                          6, "version of XML manifest."});
	XI_VERSION_ITEMS.push_back({"XI_VER_HW_REV",                          7, "version of hardware revision."});
	XI_VERSION_ITEMS.push_back({"XI_VER_FACTORY_SET",                     8, "version of factory set."});

	// Test Pattern Type
	XI_TEST_PATTERN_ITEMS.push_back({"XI_TESTPAT_OFF",                         0, " Testpattern turned off."});
	XI_TEST_PATTERN_ITEMS.push_back({"XI_TESTPAT_BLACK",                       1, " Image is filled with darkest possible image."});
	XI_TEST_PATTERN_ITEMS.push_back({"XI_TESTPAT_WHITE",                       2, " Image is filled with brightest possible image."});
	XI_TEST_PATTERN_ITEMS.push_back({"XI_TESTPAT_GREY_HORIZ_RAMP",             3, " Image is filled horizontally with an image that goes from the darkest possible value to the brightest."});
	XI_TEST_PATTERN_ITEMS.push_back({"XI_TESTPAT_GREY_VERT_RAMP",              4, " Image is filled vertically with an image that goes from the darkest possible value to the brightest."});
	XI_TEST_PATTERN_ITEMS.push_back({"XI_TESTPAT_GREY_HORIZ_RAMP_MOVING",      5, " Image is filled horizontally with an image that goes from the darkest possible value to the brightest and moves from left to right."});
	XI_TEST_PATTERN_ITEMS.push_back({"XI_TESTPAT_GREY_VERT_RAMP_MOVING",       6, " Image is filled vertically with an image that goes from the darkest possible value to the brightest and moves from left to right."});
	XI_TEST_PATTERN_ITEMS.push_back({"XI_TESTPAT_HORIZ_LINE_MOVING",           7, " A moving horizontal line is superimposed on the live image."});
	XI_TEST_PATTERN_ITEMS.push_back({"XI_TESTPAT_VERT_LINE_MOVING",            8, " A moving vertical line is superimposed on the live image."});
	XI_TEST_PATTERN_ITEMS.push_back({"XI_TESTPAT_COLOR_BAR",                   9, " Image is filled with stripes of color including White, Black, Red, Green, Blue, Cyan, Magenta and Yellow."});
	XI_TEST_PATTERN_ITEMS.push_back({"XI_TESTPAT_FRAME_COUNTER",               10, " A frame counter is superimposed on the live image."});
	XI_TEST_PATTERN_ITEMS.push_back({"XI_TESTPAT_DEVICE_SPEC_COUNTER",         11, " 128bit counter."});

	// Decimation Pattern Format
	XI_DEC_PATTERN_ITEMS.push_back({"XI_DEC_MONO",                            1, "adjacent pixels are decimated"});
	XI_DEC_PATTERN_ITEMS.push_back({"XI_DEC_BAYER",                           2, "	Bayer pattern is preserved during pixel decimation"});

	// Binning Pattern Format
	XI_BIN_PATTERN_ITEMS.push_back({"XI_BIN_MONO",                            1, "adjacent pixels are combined"});
	XI_BIN_PATTERN_ITEMS.push_back({"XI_BIN_BAYER",                           2, "Bayer pattern is preserved during pixel combining"});

	// Binning Engine Selector
	XI_BIN_SELECTOR_ITEMS.push_back({"XI_BIN_SELECT_SENSOR",                   0, "parameters for image sensor binning are selected"});
	XI_BIN_SELECTOR_ITEMS.push_back({"XI_BIN_SELECT_DEVICE_FPGA",              1, "parameters for device (camera) FPGA decimation are selected"});
	XI_BIN_SELECTOR_ITEMS.push_back({"XI_BIN_SELECT_HOST_CPU",                 2, "parameters for Host CPU binning are selected"});

	// Selects binning mode; to be used with
	XI_BIN_MODE_ITEMS.push_back({"XI_BIN_MODE_SUM",                        0, "The response from the combined pixels will be added, resulting in increased sensitivity."});
	XI_BIN_MODE_ITEMS.push_back({"XI_BIN_MODE_AVERAGE",                    1, "The response from the combined pixels will be averaged, resulting in increased signal/noise ratio."});

	// Decimation Engine Selector
	XI_DEC_SELECTOR_ITEMS.push_back({"XI_DEC_SELECT_SENSOR",                   0, "parameters for image sensor decimation are selected"});
	XI_DEC_SELECTOR_ITEMS.push_back({"XI_DEC_SELECT_DEVICE_FPGA",              1, "parameters for device (camera) FPGA decimation are selected"});
	XI_DEC_SELECTOR_ITEMS.push_back({"XI_DEC_SELECT_HOST_CPU",                 2, "parameters for Host CPU decimation are selected"});

	// Sensor tap count enumerator.
	XI_SENSOR_TAP_CNT_ITEMS.push_back({"XI_TAP_CNT_1",                           1, "1 sensor tap selected."});
	XI_SENSOR_TAP_CNT_ITEMS.push_back({"XI_TAP_CNT_2",                           2, "2 sensor taps selected."});
	XI_SENSOR_TAP_CNT_ITEMS.push_back({"XI_TAP_CNT_4",                           4, "4 sensor taps selected."});

	// Bit depth enumerator.
	XI_BIT_DEPTH_ITEMS.push_back({"XI_BPP_8",                               8, "8 bit per pixel"});
	XI_BIT_DEPTH_ITEMS.push_back({"XI_BPP_9",                               9, "9 bit per pixel"});
	XI_BIT_DEPTH_ITEMS.push_back({"XI_BPP_10",                              10, "10 bit per pixel"});
	XI_BIT_DEPTH_ITEMS.push_back({"XI_BPP_11",                              11, "11 bit per pixel"});
	XI_BIT_DEPTH_ITEMS.push_back({"XI_BPP_12",                              12, "12 bit per pixel"});
	XI_BIT_DEPTH_ITEMS.push_back({"XI_BPP_14",                              14, "14 bit per pixel"});
	XI_BIT_DEPTH_ITEMS.push_back({"XI_BPP_16",                              16, "16 bit per pixel"});
	XI_BIT_DEPTH_ITEMS.push_back({"XI_BPP_24",                              24, "24 bit per pixel"});
	XI_BIT_DEPTH_ITEMS.push_back({"XI_BPP_32",                              32, "32 bit per pixel"});

	// Debug level enumerator.
	XI_DEBUG_LEVEL_ITEMS.push_back({"XI_DL_DETAIL",                           0, "(see Note1)"});
	XI_DEBUG_LEVEL_ITEMS.push_back({"XI_DL_TRACE",                            1, "Prints errors, warnings and important informations"});
	XI_DEBUG_LEVEL_ITEMS.push_back({"XI_DL_WARNING",                          2, "Prints all errors and warnings"});
	XI_DEBUG_LEVEL_ITEMS.push_back({"XI_DL_ERROR",                            3, "Prints all errors"});
	XI_DEBUG_LEVEL_ITEMS.push_back({"XI_DL_FATAL",                            4, "Prints only important errors"});
	XI_DEBUG_LEVEL_ITEMS.push_back({"XI_DL_DISABLED",                         100, "Prints no messages"});

	// Image output format enumerator.
	XI_IMG_FORMAT_ITEMS.push_back({"XI_MONO8",                               0, "8 bits per pixel. 	[Intensity] (see Note5,Note6)"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_MONO16",                              1, "16 bits per pixel. [Intensity LSB] [Intensity MSB] (see Note5,Note6)"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_RGB24",                               2, "RGB data format. [Blue][Green][Red] (see Note5)"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_RGB32",                               3, "RGBA data format. 	[Blue][Green][Red][0] (see Note5)"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_RGB_PLANAR",                          4, "RGB planar data format. [Red][Red]...[Green][Green]...[Blue][Blue]... (see Note5)"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_RAW8",                                5, "8 bits per pixel raw data from sensor. 	[pixel byte] raw data from transport (camera output)"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_RAW16",                               6, "16 bits per pixel raw data from sensor. 	[pixel byte low] [pixel byte high] 16 bits (depacked) raw data"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_FRM_TRANSPORT_DATA",                  7, "Data from transport layer (e.g. packed). Depends on data on the transport layer (see Note7)"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_RGB48",                               8, "RGB data format. [Blue low byte][Blue high byte][Green low][Green high][Red low][Red high] (see Note5)"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_RGB64",                               9, "RGBA data format. [Blue low byte][Blue high byte][Green low][Green high][Red low][Red high][0][0] (Note5)"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_RGB16_PLANAR",                        10, "RGB16 planar data format"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_RAW8X2",                              11, "8 bits per pixel raw data from sensor(2 components in a row). [ch1 pixel byte] [ch2 pixel byte] 8 bits raw data from 2 channels (e.g. high gain and low gain channels of sCMOS cameras)"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_RAW8X4",                              12, "8 bits per pixel raw data from sensor(4 components in a row). 	[ch1 pixel byte [ch2 pixel byte] [ch3 pixel byte] [ch4 pixel byte] 8 bits raw data from 4 channels (e.g. sCMOS cameras)"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_RAW16X2",                             13, "16 bits per pixel raw data from sensor(2 components in a row). 	[ch1 pixel byte low] [ch1 pixel byte high] [ch2 pixel byte low] [ch2 pixel byte high] 16 bits (depacked) raw data from 2 channels (e.g. high gain and low gain channels of sCMOS cameras)"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_RAW16X4",                             14, "16 bits per pixel raw data from sensor(4 components in a row). 	[ch1 pixel byte low] [ch1 pixel byte high] [ch2 pixel byte low] [ch2 pixel byte high] [ch3 pixel byte low] [ch3 pixel byte high] [ch4 pixel byte low] [ch4 pixel byte high] 16 bits (depacked) raw data from 4 channels (e.g. sCMOS cameras)"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_RAW32",                               15, "32 bits per pixel raw data from sensor in integer format (LSB first). 4 bytes (LSB first) pixel (depacked) raw data"});
	XI_IMG_FORMAT_ITEMS.push_back({"XI_RAW32FLOAT",                          16, "32 bits per pixel raw data from sensor in single-precision floating point format. 4 bytes per pixel (depacked) raw data"});

	// Bayer color matrix enumerator.
	XI_COLOR_FILTER_ARRAY_ITEMS.push_back({"XI_CFA_NONE",                            0, "Result pixels have no filters applied in this format"});
	XI_COLOR_FILTER_ARRAY_ITEMS.push_back({"XI_CFA_BAYER_RGGB",                      1, "Regular RGGB"});
	XI_COLOR_FILTER_ARRAY_ITEMS.push_back({"XI_CFA_CMYG",                            2, "AK Sony sens"});
	XI_COLOR_FILTER_ARRAY_ITEMS.push_back({"XI_CFA_RGR",                             3, "2R+G readout"});
	XI_COLOR_FILTER_ARRAY_ITEMS.push_back({"XI_CFA_BAYER_BGGR",                      4, "BGGR readout"});
	XI_COLOR_FILTER_ARRAY_ITEMS.push_back({"XI_CFA_BAYER_GRBG",                      5, "GRBG readout"});
	XI_COLOR_FILTER_ARRAY_ITEMS.push_back({"XI_CFA_BAYER_GBRG",                      6, "GBRG readout"});
	XI_COLOR_FILTER_ARRAY_ITEMS.push_back({"XI_CFA_POLAR_A_BAYER_BGGR",              7, "BGGR polarized 4x4 macropixel"});
	XI_COLOR_FILTER_ARRAY_ITEMS.push_back({"XI_CFA_POLAR_A",                         8, "Polarized 2x2 macropixel"});

	// structure containing information about buffer policy(can be safe, data will be copied to user/app buffer or unsafe, user will get internally allocated buffer without data copy).
	XI_BP_ITEMS.push_back({"XI_BP_UNSAFE",                           0, "User gets pointer to internally allocated circle buffer and data may be overwritten by device."});
	XI_BP_ITEMS.push_back({"XI_BP_SAFE",                             1, "Data from device will be copied to user allocated buffer or xiApi allocated memory."});

	// structure containing information about trigger source
	XI_TRG_SOURCE_ITEMS.push_back({"XI_TRG_OFF",                             0, "Capture of next image is automatically started after previous."});
	XI_TRG_SOURCE_ITEMS.push_back({"XI_TRG_EDGE_RISING",                     1, "Capture is started on rising edge of selected input."});
	XI_TRG_SOURCE_ITEMS.push_back({"XI_TRG_EDGE_FALLING",                    2, "Capture is started on falling edge of selected input"});
	XI_TRG_SOURCE_ITEMS.push_back({"XI_TRG_SOFTWARE",                        3, "Capture is started with software trigger."});
	XI_TRG_SOURCE_ITEMS.push_back({"XI_TRG_LEVEL_HIGH",                      4, "Specifies that the trigger is considered valid as long as the level of the source signal is high."});
	XI_TRG_SOURCE_ITEMS.push_back({"XI_TRG_LEVEL_LOW",                       5, "Specifies that the trigger is considered valid as long as the level of the source signal is low."});

	// structure containing information about trigger functionality
	XI_TRG_SELECTOR_ITEMS.push_back({"XI_TRG_SEL_FRAME_START",                 0, "Trigger starts the capture of one frame"});
	XI_TRG_SELECTOR_ITEMS.push_back({"XI_TRG_SEL_EXPOSURE_ACTIVE",             1, "Trigger controls the start and length of the exposure."});
	XI_TRG_SELECTOR_ITEMS.push_back({"XI_TRG_SEL_FRAME_BURST_START",           2, "Trigger starts the capture of the bursts of frames in an acquisition."});
	XI_TRG_SELECTOR_ITEMS.push_back({"XI_TRG_SEL_FRAME_BURST_ACTIVE",          3, "Trigger controls the duration of the capture of the bursts of frames in an acquisition."});
	XI_TRG_SELECTOR_ITEMS.push_back({"XI_TRG_SEL_MULTIPLE_EXPOSURES",          4, "Trigger which when first trigger starts exposure and consequent pulses are gating exposure(active HI)"});
	XI_TRG_SELECTOR_ITEMS.push_back({"XI_TRG_SEL_EXPOSURE_START",              5, "Trigger controls the start of the exposure of one Frame."});
	XI_TRG_SELECTOR_ITEMS.push_back({"XI_TRG_SEL_MULTI_SLOPE_PHASE_CHANGE",    6, "Trigger controls the multi slope phase in one Frame (phase0 -> phase1) or (phase1 -> phase2)."});
	XI_TRG_SELECTOR_ITEMS.push_back({"XI_TRG_SEL_ACQUISITION_START",           7, "Trigger starts acquisition of first frame."});

	// Trigger overlap modes
	XI_TRG_OVERLAP_ITEMS.push_back({"XI_TRG_OVERLAP_OFF",                     0, "No trigger overlap is permitted. If camera is in read-out phase, all triggers are rejected."});
	XI_TRG_OVERLAP_ITEMS.push_back({"XI_TRG_OVERLAP_READ_OUT",                1, "Trigger is accepted only when sensor is ready to start next exposure with defined exposure time. Trigger is rejected when sensor is not ready for new exposure with defined exposure time. (see Note1)"});
	XI_TRG_OVERLAP_ITEMS.push_back({"XI_TRG_OVERLAP_PREV_FRAME",              2, "Trigger is accepted by camera any time. If sensor is not ready for the next exposure - the trigger is latched and sensor starts exposure as soon as exposure can be started with defined exposure time."});

	// structure containing information about acquisition timing modes
	XI_ACQ_TIMING_MODE_ITEMS.push_back({"XI_ACQ_TIMING_MODE_FREE_RUN",            0, "camera acquires images at a maximum possible framerate"});
	XI_ACQ_TIMING_MODE_ITEMS.push_back({"XI_ACQ_TIMING_MODE_FRAME_RATE",          1, "Selects a mode when sensor frame acquisition frequency is set to parameter FRAMERATE"});
	XI_ACQ_TIMING_MODE_ITEMS.push_back({"XI_ACQ_TIMING_MODE_FRAME_RATE_LIMIT",    2, "Selects a mode when sensor frame acquisition frequency is limited by parameter FRAMERATE"});

	// Enumerator for data target modes
	XI_TRANSPORT_DATA_TARGET_MODE_ITEMS.push_back({"XI_TRANSPORT_DATA_TARGET_CPU_RAM",       0, "normal CPU memory buffer is used for image data"});
	XI_TRANSPORT_DATA_TARGET_MODE_ITEMS.push_back({"XI_TRANSPORT_DATA_TARGET_GPU_RAM",       1, "data is delivered straight to GPU memory using GPUDirect technology"});
	XI_TRANSPORT_DATA_TARGET_MODE_ITEMS.push_back({"XI_TRANSPORT_DATA_TARGET_UNIFIED",       2, "CUDA managed memory is used for image data."});
	XI_TRANSPORT_DATA_TARGET_MODE_ITEMS.push_back({"XI_TRANSPORT_DATA_TARGET_ZEROCOPY",      3, "CUDA zerocopy memory is used for image data."});

	// Enumeration for XI_PRM_GPI_SELECTOR for CB cameras.
	XI_GPI_SEL_CB_ITEMS.push_back({"XI_GPI_SEL_CB_IN1",                      1, "Input1 - Pin3 (Opto Isolated)."});
	XI_GPI_SEL_CB_ITEMS.push_back({"XI_GPI_SEL_CB_IN2",                      2, "Input2 - Pin4 (Opto Isolated)."});
	XI_GPI_SEL_CB_ITEMS.push_back({"XI_GPI_SEL_CB_INOUT1",                   3, "Input/Output1 - Pin6"});
	XI_GPI_SEL_CB_ITEMS.push_back({"XI_GPI_SEL_CB_INOUT2",                   4, "Input/Output2 - Pin7"});
	XI_GPI_SEL_CB_ITEMS.push_back({"XI_GPI_SEL_CB_INOUT3",                   5, "Input/Output3 - Pin11"});
	XI_GPI_SEL_CB_ITEMS.push_back({"XI_GPI_SEL_CB_INOUT4",                   6, "Input/Output4 - Pin12"});

	// Enumeration for XI_PRM_GPO_SELECTOR for CB cameras.
	XI_GPO_SEL_CB_ITEMS.push_back({"XI_GPO_SEL_CB_OUT1",                     1, "Output1 - Pin8 (Opto Isolated)."});
	XI_GPO_SEL_CB_ITEMS.push_back({"XI_GPO_SEL_CB_OUT2",                     2, "Output2 - Pin9 (Opto Isolated)."});
	XI_GPO_SEL_CB_ITEMS.push_back({"XI_GPO_SEL_CB_INOUT1",                   3, "Input/Output1 - Pin6"});
	XI_GPO_SEL_CB_ITEMS.push_back({"XI_GPO_SEL_CB_INOUT2",                   4, "Input/Output2 - Pin7"});
	XI_GPO_SEL_CB_ITEMS.push_back({"XI_GPO_SEL_CB_INOUT3",                   5, "Input/Output3 - Pin11"});
	XI_GPO_SEL_CB_ITEMS.push_back({"XI_GPO_SEL_CB_INOUT4",                   6, "Input/Output4 - Pin12"});

	// structure containing information about GPI functionality
	XI_GPI_MODE_ITEMS.push_back({"XI_GPI_OFF",                             0, "Input is not used for triggering, but can be used to get parameter GPI_LEVEL. This can be used to switch I/O line on some cameras to input mode."});
	XI_GPI_MODE_ITEMS.push_back({"XI_GPI_TRIGGER",                         1, "Input can be used for triggering."});
	XI_GPI_MODE_ITEMS.push_back({"XI_GPI_EXT_EVENT",                       2, "External signal input (not implemented)"});

	// Enumerator for GPI port selection.
	XI_GPI_SELECTOR_ITEMS.push_back({"XI_GPI_PORT1",                           1, "GPI port 1"});
	XI_GPI_SELECTOR_ITEMS.push_back({"XI_GPI_PORT2",                           2, "GPI port 2"});
	XI_GPI_SELECTOR_ITEMS.push_back({"XI_GPI_PORT3",                           3, "GPI port 3"});
	XI_GPI_SELECTOR_ITEMS.push_back({"XI_GPI_PORT4",                           4, "GPI port 4"});
	XI_GPI_SELECTOR_ITEMS.push_back({"XI_GPI_PORT5",                           5, "GPI port 5"});
	XI_GPI_SELECTOR_ITEMS.push_back({"XI_GPI_PORT6",                           6, "GPI port 6"});
	XI_GPI_SELECTOR_ITEMS.push_back({"XI_GPI_PORT7",                           7, "GPI port 7"});
	XI_GPI_SELECTOR_ITEMS.push_back({"XI_GPI_PORT8",                           8, "GPI port 8"});
	XI_GPI_SELECTOR_ITEMS.push_back({"XI_GPI_PORT9",                           9, "GPI port 9"});
	XI_GPI_SELECTOR_ITEMS.push_back({"XI_GPI_PORT10",                          10, "GPI port 10"});
	XI_GPI_SELECTOR_ITEMS.push_back({"XI_GPI_PORT11",                          11, "GPI port 11"});
	XI_GPI_SELECTOR_ITEMS.push_back({"XI_GPI_PORT12",                          12, "GPI port 12"});

	// structure containing information about GPO functionality
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_OFF",                             0, "Output is off (zero voltage or switched_off)"});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_ON",                              1, "Output is on (voltage or switched_on)"});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_FRAME_ACTIVE",                    2, "Output is on while frame exposure,read,transfer."});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_FRAME_ACTIVE_NEG",                3, "Output is off while frame exposure,read,transfer."});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_EXPOSURE_ACTIVE",                 4, "Output is on while frame exposure"});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_EXPOSURE_ACTIVE_NEG",             5, "Output is off while frame exposure"});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_FRAME_TRIGGER_WAIT",              6, "Output is on while camera is ready for trigger"});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_FRAME_TRIGGER_WAIT_NEG",          7, "Output is off while camera is ready for trigger."});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_EXPOSURE_PULSE",                  8, "Output is on short pulse at the beginning of frame exposure."});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_EXPOSURE_PULSE_NEG",              9, "Output is off short pulse at the beginning of frame exposure."});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_BUSY",                            10, "Output is on when camera has received trigger until end of transfer"});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_BUSY_NEG",                        11, "Output is off when camera has received trigger until end of transfer"});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_HIGH_IMPEDANCE",                  12, "Associated pin is in high impedance (tri-stated) and can be driven externally. E.g. for triggering or reading status by GPI_LEVEL."});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_FRAME_BUFFER_OVERFLOW",           13, "Frame buffer overflow status."});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_EXPOSURE_ACTIVE_FIRST_ROW",       14, "Output is on while the first row exposure."});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_EXPOSURE_ACTIVE_FIRST_ROW_NEG",   15, "Output is off while the first row exposure."});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_EXPOSURE_ACTIVE_ALL_ROWS",        16, "Output is on while all rows exposure together."});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_EXPOSURE_ACTIVE_ALL_ROWS_NEG",    17, "Output is off while all rows exposure together."});
	XI_GPO_MODE_ITEMS.push_back({"XI_GPO_TXD",                             18, "Output is connected to TXD of UART module"});

	// Enumerator for GPO port selection.
	XI_GPO_SELECTOR_ITEMS.push_back({"XI_GPO_PORT1",                           1, "GPO port 1"});
	XI_GPO_SELECTOR_ITEMS.push_back({"XI_GPO_PORT2",                           2, "GPO port 2"});
	XI_GPO_SELECTOR_ITEMS.push_back({"XI_GPO_PORT3",                           3, "GPO port 3"});
	XI_GPO_SELECTOR_ITEMS.push_back({"XI_GPO_PORT4",                           4, "GPO port 4"});
	XI_GPO_SELECTOR_ITEMS.push_back({"XI_GPO_PORT5",                           5, "GPO port 5"});
	XI_GPO_SELECTOR_ITEMS.push_back({"XI_GPO_PORT6",                           6, "GPO port 6"});
	XI_GPO_SELECTOR_ITEMS.push_back({"XI_GPO_PORT7",                           7, "GPO port 7"});
	XI_GPO_SELECTOR_ITEMS.push_back({"XI_GPO_PORT8",                           8, "GPO port 8"});
	XI_GPO_SELECTOR_ITEMS.push_back({"XI_GPO_PORT9",                           9, "GPO port 9"});
	XI_GPO_SELECTOR_ITEMS.push_back({"XI_GPO_PORT10",                          10, "GPO port 10"});
	XI_GPO_SELECTOR_ITEMS.push_back({"XI_GPO_PORT11",                          11, "GPO port 11"});
	XI_GPO_SELECTOR_ITEMS.push_back({"XI_GPO_PORT12",                          12, "GPO port 12"});

	// structure containing information about LED functionality
	XI_LED_MODE_ITEMS.push_back({"XI_LED_HEARTBEAT",                       0, "Set led to blink (1 Hz) if link is OK."});
	XI_LED_MODE_ITEMS.push_back({"XI_LED_TRIGGER_ACTIVE",                  1, "Set led to blink if trigger detected."});
	XI_LED_MODE_ITEMS.push_back({"XI_LED_EXT_EVENT_ACTIVE",                2, "Set led to blink if external signal detected."});
	XI_LED_MODE_ITEMS.push_back({"XI_LED_LINK",                            3, "Set led to blink if link is OK."});
	XI_LED_MODE_ITEMS.push_back({"XI_LED_ACQUISITION",                     4, "Set led to blink if data streaming"});
	XI_LED_MODE_ITEMS.push_back({"XI_LED_EXPOSURE_ACTIVE",                 5, "Set led to blink if sensor integration time."});
	XI_LED_MODE_ITEMS.push_back({"XI_LED_FRAME_ACTIVE",                    6, "Set led to blink if device busy/not busy."});
	XI_LED_MODE_ITEMS.push_back({"XI_LED_OFF",                             7, "Set led to off."});
	XI_LED_MODE_ITEMS.push_back({"XI_LED_ON",                              8, "Set led to on."});
	XI_LED_MODE_ITEMS.push_back({"XI_LED_BLINK",                           9, "Blinking (1Hz)."});

	// Enumerator for LED selection.
	XI_LED_SELECTOR_ITEMS.push_back({"XI_LED_SEL1",                            1, "LED 1"});
	XI_LED_SELECTOR_ITEMS.push_back({"XI_LED_SEL2",                            2, "LED 2"});
	XI_LED_SELECTOR_ITEMS.push_back({"XI_LED_SEL3",                            3, "LED 3"});
	XI_LED_SELECTOR_ITEMS.push_back({"XI_LED_SEL4",                            4, "LED 4"});
	XI_LED_SELECTOR_ITEMS.push_back({"XI_LED_SEL5",                            5, "LED 5"});

	// structure contains frames counter
	XI_COUNTER_SELECTOR_ITEMS.push_back({"XI_CNT_SEL_TRANSPORT_SKIPPED_FRAMES",    0, "Number of skipped frames on transport layer (e.g. when image gets lost while transmission). Occur when capacity of transport channel does not allow to transfer all data."});
	XI_COUNTER_SELECTOR_ITEMS.push_back({"XI_CNT_SEL_API_SKIPPED_FRAMES",          1, "Number of skipped frames on API layer. Occur when application does not process the images as quick as they are received from the camera."});
	XI_COUNTER_SELECTOR_ITEMS.push_back({"XI_CNT_SEL_TRANSPORT_TRANSFERRED_FRAMES",2, "Number of delivered buffers since last acquisition start."});
	XI_COUNTER_SELECTOR_ITEMS.push_back({"XI_CNT_SEL_FRAME_MISSED_TRIGGER_DUETO_OVERLAP",3, "Number of missed triggers due to overlap. (see Note2)"});
	XI_COUNTER_SELECTOR_ITEMS.push_back({"XI_CNT_SEL_FRAME_MISSED_TRIGGER_DUETO_FRAME_BUFFER_OVR",4, "Number of missed triggers due to frame buffer full. (see Note2)"});
	XI_COUNTER_SELECTOR_ITEMS.push_back({"XI_CNT_SEL_FRAME_BUFFER_OVERFLOW",       5, "Frame buffer full counter. (see Note2)"});

	// structure containing information about timestamp reset arming
	XI_TS_RST_MODE_ITEMS.push_back({"XI_TS_RST_ARM_ONCE",                     0, "Engine is disabled after TimeStamp has been reset after selected event."});
	XI_TS_RST_MODE_ITEMS.push_back({"XI_TS_RST_ARM_PERSIST",                  1, "Engine is armed permanently so each selected event will trigger TimeStamp reset. "});

	// structure containing information about possible timestamp reset sources
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_OFF",                          0, "No source selected TimeStamp reset is not armed."});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_1",                    1, "GPI1 rising edge is active (signal after de-bounce module)"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_2",                    2, "GPI2 rising edge is active"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_3",                    3, "GPI3 rising edge is active"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_4",                    4, "GPI4 rising edge is active"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_1_INV",                5, "GPI1 falling edge is active"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_2_INV",                6, "GPI2 falling edge is active"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_3_INV",                7, "GPI3 falling edge is active"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_4_INV",                8, "GPI4 falling edge is active"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPO_1",                    9, "TimeStamp reset source selected GPO1"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPO_2",                    10, "TimeStamp reset source selected GPO2"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPO_3",                    11, "TimeStamp reset source selected GPO3"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPO_4",                    12, "TimeStamp reset source selected GPO4"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPO_1_INV",                13, "TimeStamp reset source selected GPO1 inverted"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPO_2_INV",                14, "TimeStamp reset source selected GPO2 inverted"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPO_3_INV",                15, "TimeStamp reset source selected GPO3 inverted"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPO_4_INV",                16, "TimeStamp reset source selected GPO4 inverted"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_TRIGGER",                  17, "TRIGGER to sensor rising edge is active"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_TRIGGER_INV",              18, "TRIGGER to sensor rising edge is active"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_SW",                       19, "TRIGGER to sensor rising edge is active. TimeStamp is reset by software take effect imminently."});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_EXPACTIVE",                20, "Exposure Active signal rising edge "});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_EXPACTIVE_INV",            21, "Exposure Active signal falling edge "});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_FVAL",                     22, "Frame valid signal rising edge (internal signal in camera)"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_FVAL_INV",                 23, "Frame valid signal falling edge (internal signal in camera)"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_5",                    24, "GPI5 rising edge is active"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_6",                    25, "GPI6 rising edge is active"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_5_INV",                26, "GPI5 falling edge is active"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_6_INV",                27, "GPI6 falling edge is active"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_7",                    28, "TimeStamp reset source selected GPI7 (after de bounce)"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_8",                    29, "TimeStamp reset source selected GPI8 (after de bounce)"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_9",                    30, "TimeStamp reset source selected GPI9 (after de bounce)"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_10",                   31, "TimeStamp reset source selected GPI10 (after de bounce)"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_11",                   32, "TimeStamp reset source selected GPI11 (after de bounce)"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_7_INV",                33, "TimeStamp reset source selected GPI7 inverted (after de bounce)"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_8_INV",                34, "TimeStamp reset source selected GPI8 inverted (after de bounce)"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_9_INV",                35, "TimeStamp reset source selected GPI9 inverted (after de bounce)"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_10_INV",               36, "TimeStamp reset source selected GPI10 inverted (after de bounce)"});
	XI_TS_RST_SOURCE_ITEMS.push_back({"XI_TS_RST_SRC_GPI_11_INV",               37, "TimeStamp reset source selected GPI11 inverted (after de bounce)"});

	// structure containing information about parameters type
	XI_PRM_TYPE_ITEMS.push_back({"xiTypeInteger",                          0, "integer parameter type"});
	XI_PRM_TYPE_ITEMS.push_back({"xiTypeFloat",                            1, "float parameter type"});
	XI_PRM_TYPE_ITEMS.push_back({"xiTypeString",                           2, "string parameter type"});
	XI_PRM_TYPE_ITEMS.push_back({"xiTypeEnum",                             3, "enumerator parameter type"});
	XI_PRM_TYPE_ITEMS.push_back({"xiTypeBoolean",                          4, "boolean parameter type"});
	XI_PRM_TYPE_ITEMS.push_back({"xiTypeCommand",                          5, "command parameter type"});
	XI_PRM_TYPE_ITEMS.push_back({"xiTypeInteger64",                        6, "64bit integer parameter type"});

	// Turn parameter On/Off
	XI_SWITCH_ITEMS.push_back({"XI_OFF",                                 0, "Turn parameter off"});
	XI_SWITCH_ITEMS.push_back({"XI_ON",                                  1, "Turn parameter on"});

	// Temperature selector
	XI_TEMP_SELECTOR_ITEMS.push_back({"XI_TEMP_IMAGE_SENSOR_DIE_RAW",           0, "Image sensor die (non-calibrated)"});
	XI_TEMP_SELECTOR_ITEMS.push_back({"XI_TEMP_IMAGE_SENSOR_DIE",               1, "Image sensor die (calibrated)"});
	XI_TEMP_SELECTOR_ITEMS.push_back({"XI_TEMP_SENSOR_BOARD",                   2, "Image sensor PCB"});
	XI_TEMP_SELECTOR_ITEMS.push_back({"XI_TEMP_INTERFACE_BOARD",                3, "Data interface PCB"});
	XI_TEMP_SELECTOR_ITEMS.push_back({"XI_TEMP_FRONT_HOUSING",                  4, "Front part of camera housing"});
	XI_TEMP_SELECTOR_ITEMS.push_back({"XI_TEMP_REAR_HOUSING",                   5, "Rear part of camera housing"});
	XI_TEMP_SELECTOR_ITEMS.push_back({"XI_TEMP_TEC1_COLD",                      6, "TEC1 cold side temperature"});
	XI_TEMP_SELECTOR_ITEMS.push_back({"XI_TEMP_TEC1_HOT",                       7, "TEC1 hot side temperature"});

	// Temperature selector
	XI_TEMP_CTRL_MODE_SELECTOR_ITEMS.push_back({"XI_TEMP_CTRL_MODE_OFF",                  0, "Controlling of elements (TEC/Peltier, Fans) is turned off"});
	XI_TEMP_CTRL_MODE_SELECTOR_ITEMS.push_back({"XI_TEMP_CTRL_MODE_AUTO",                 1, "Controlling of elements is performed automatically by API or camera in order to reach parameter TARGET_TEMP."});
	XI_TEMP_CTRL_MODE_SELECTOR_ITEMS.push_back({"XI_TEMP_CTRL_MODE_MANUAL",               2, "Controlling of elements is done manually by application."});

	// Temperature element selector
	XI_TEMP_ELEMENT_SELECTOR_ITEMS.push_back({"XI_TEMP_ELEM_TEC1",                      11, "TEC1 = TEC/Peltier that is closest to the image sensor"});
	XI_TEMP_ELEMENT_SELECTOR_ITEMS.push_back({"XI_TEMP_ELEM_TEC2",                      12, "TEC2 = TEC/Peltier location depends on camera model"});
	XI_TEMP_ELEMENT_SELECTOR_ITEMS.push_back({"XI_TEMP_ELEM_FAN1",                      31, "Temperature element fan current or rotation (FAN1 = Fan)"});
	XI_TEMP_ELEMENT_SELECTOR_ITEMS.push_back({"XI_TEMP_ELEM_FAN1_THRS_TEMP",            32, "Temperature element fan start rotation threshold temperature"});

	// Data packing(grouping) types.
	XI_OUTPUT_DATA_PACKING_TYPE_ITEMS.push_back({"XI_DATA_PACK_XI_GROUPING",               0, "Data grouping (10g160, 12g192, 14g224)."});
	XI_OUTPUT_DATA_PACKING_TYPE_ITEMS.push_back({"XI_DATA_PACK_PFNC_LSB_PACKING",          1, "Data packing (10p, 12p)"});

	// Downsampling types
	XI_DOWNSAMPLING_TYPE_ITEMS.push_back({"XI_BINNING",                             0, "pixels are interpolated - better image"});
	XI_DOWNSAMPLING_TYPE_ITEMS.push_back({"XI_SKIPPING",                            1, "pixels are skipped - higher frame rate"});

	// Exposure time selector
	XI_EXPOSURE_TIME_SELECTOR_TYPE_ITEMS.push_back({"XI_EXPOSURE_TIME_SELECTOR_COMMON",       0, "Selects the common Exposure Time"});
	XI_EXPOSURE_TIME_SELECTOR_TYPE_ITEMS.push_back({"XI_EXPOSURE_TIME_SELECTOR_GROUP1",       1, "Selects the common Exposure Time for pixel group 1 (for InterlineExposureMode)"});
	XI_EXPOSURE_TIME_SELECTOR_TYPE_ITEMS.push_back({"XI_EXPOSURE_TIME_SELECTOR_GROUP2",       2, "Selects the common Exposure Time for pixel group 2 (for InterlineExposureMode)"});

	// Interline exposure mode
	XI_INTERLINE_EXPOSURE_MODE_TYPE_ITEMS.push_back({"XI_INTERLINE_EXPOSURE_MODE_OFF",         0, "Disabled"});
	XI_INTERLINE_EXPOSURE_MODE_TYPE_ITEMS.push_back({"XI_INTERLINE_EXPOSURE_MODE_ON",          1, "Enabled"});

	// Gain selector
	XI_GAIN_SELECTOR_TYPE_ITEMS.push_back({"XI_GAIN_SELECTOR_ALL",                   0, "Gain selector selects all channels. Implementation of gain type depends on camera."});
	XI_GAIN_SELECTOR_TYPE_ITEMS.push_back({"XI_GAIN_SELECTOR_ANALOG_ALL",            1, "Gain selector selects all analog channels. This is available only on some cameras."});
	XI_GAIN_SELECTOR_TYPE_ITEMS.push_back({"XI_GAIN_SELECTOR_DIGITAL_ALL",           2, "Gain selector selects all digital channels. This is available only on some cameras."});
	XI_GAIN_SELECTOR_TYPE_ITEMS.push_back({"XI_GAIN_SELECTOR_ANALOG_TAP1",           3, "Gain selector selects tap 1. This is available only on some cameras."});
	XI_GAIN_SELECTOR_TYPE_ITEMS.push_back({"XI_GAIN_SELECTOR_ANALOG_TAP2",           4, "Gain selector selects tap 2. This is available only on some cameras."});
	XI_GAIN_SELECTOR_TYPE_ITEMS.push_back({"XI_GAIN_SELECTOR_ANALOG_TAP3",           5, "Gain selector selects tap 3. This is available only on some cameras."});
	XI_GAIN_SELECTOR_TYPE_ITEMS.push_back({"XI_GAIN_SELECTOR_ANALOG_TAP4",           6, "Gain selector selects tap 4. This is available only on some cameras."});
	XI_GAIN_SELECTOR_TYPE_ITEMS.push_back({"XI_GAIN_SELECTOR_ANALOG_N",              7, "Gain selector selects North column analog gain. This is available only on some cameras."});
	XI_GAIN_SELECTOR_TYPE_ITEMS.push_back({"XI_GAIN_SELECTOR_ANALOG_S",              8, "Gain selector selects South column analog gain. This is available only on some cameras."});

	// Shutter mode types
	XI_SHUTTER_TYPE_ITEMS.push_back({"XI_SHUTTER_GLOBAL",                      0, "Sensor Global Shutter(CMOS sensor)"});
	XI_SHUTTER_TYPE_ITEMS.push_back({"XI_SHUTTER_ROLLING",                     1, "Sensor Electronic Rolling Shutter(CMOS sensor)"});
	XI_SHUTTER_TYPE_ITEMS.push_back({"XI_SHUTTER_GLOBAL_RESET_RELEASE",        2, "Sensor Global Reset Release Shutter(CMOS sensor)"});

	// structure containing information about CMS functionality
	XI_CMS_MODE_ITEMS.push_back({"XI_CMS_DIS",                             0, "disables color management"});
	XI_CMS_MODE_ITEMS.push_back({"XI_CMS_EN",                              1, "enables color management (high CPU usage)"});
	XI_CMS_MODE_ITEMS.push_back({"XI_CMS_EN_FAST",                         2, "enables fast color management (high RAM usage)"});

	// structure containing information about ICC Intents
	XI_CMS_INTENT_ITEMS.push_back({"XI_CMS_INTENT_PERCEPTUAL",               0, "CMS intent perceptual"});
	XI_CMS_INTENT_ITEMS.push_back({"XI_CMS_INTENT_RELATIVE_COLORIMETRIC",    1, "CMS intent relative colorimetry"});
	XI_CMS_INTENT_ITEMS.push_back({"XI_CMS_INTENT_SATURATION",               2, "CMS intent saturation"});
	XI_CMS_INTENT_ITEMS.push_back({"XI_CMS_INTENT_ABSOLUTE_COLORIMETRIC",    3, "CMS intent absolute colorimetry"});

	// structure containing information about options for selection of camera before opening
	XI_OPEN_BY_ITEMS.push_back({"XI_OPEN_BY_INST_PATH",                   0, "Open camera by its hardware path"});
	XI_OPEN_BY_ITEMS.push_back({"XI_OPEN_BY_SN",                          1, "Open camera by its serial number"});
	XI_OPEN_BY_ITEMS.push_back({"XI_OPEN_BY_USER_ID",                     2, "open camera by its custom user ID"});
	XI_OPEN_BY_ITEMS.push_back({"XI_OPEN_BY_LOC_PATH",                    3, "Open camera by its hardware location path"});

	// Lens feature selector selects which feature will be accessed.
	XI_LENS_FEATURE_ITEMS.push_back({"XI_LENS_FEATURE_MOTORIZED_FOCUS_SWITCH", 1, "Status of lens motorized focus switch"});
	XI_LENS_FEATURE_ITEMS.push_back({"XI_LENS_FEATURE_MOTORIZED_FOCUS_BOUNDED",2, "On read = 1 if motorized focus is on one of limits."});
	XI_LENS_FEATURE_ITEMS.push_back({"XI_LENS_FEATURE_MOTORIZED_FOCUS_CALIBRATION",3, "(planned feature) On read = 1 if motorized focus is calibrated. Write 1 to start calibration."});
	XI_LENS_FEATURE_ITEMS.push_back({"XI_LENS_FEATURE_IMAGE_STABILIZATION_ENABLED",4, "On read = 1 if image stabilization is enabled. Write 1 to enable image stabilization."});
	XI_LENS_FEATURE_ITEMS.push_back({"XI_LENS_FEATURE_IMAGE_STABILIZATION_SWITCH_STATUS",5, "On read = 1 if image stabilization switch is in position On."});
	XI_LENS_FEATURE_ITEMS.push_back({"XI_LENS_FEATURE_IMAGE_ZOOM_SUPPORTED",   6, "On read = 1 if lens supports zoom = are not prime."});

	// Sensor feature selector selects which feature will be accessed.
	XI_SENSOR_FEATURE_SELECTOR_ITEMS.push_back({"XI_SENSOR_FEATURE_ZEROROT_ENABLE",       0, "Zero ROT enable for ONSEMI PYTHON family. For camera model:MQ013xG-ON "});
	XI_SENSOR_FEATURE_SELECTOR_ITEMS.push_back({"XI_SENSOR_FEATURE_BLACK_LEVEL_CLAMP",    1, "Black level offset clamping. for Camera model:MD"});
	XI_SENSOR_FEATURE_SELECTOR_ITEMS.push_back({"XI_SENSOR_FEATURE_MD_FPGA_DIGITAL_GAIN_DISABLE",2, "Disable digital component of gain for MD family"});
	XI_SENSOR_FEATURE_SELECTOR_ITEMS.push_back({"XI_SENSOR_FEATURE_ACQUISITION_RUNNING",  3, "Sensor acquisition is running status. Could be stopped by setting of 0. For camera model:CB,MC,MX,MT"});
	XI_SENSOR_FEATURE_SELECTOR_ITEMS.push_back({"XI_SENSOR_FEATURE_TIMING_MODE",          4, "Set Sensor timing mode"});
	XI_SENSOR_FEATURE_SELECTOR_ITEMS.push_back({"XI_SENSOR_FEATURE_PARALLEL_ADC",         5, "Parallel ADC readout"});
	XI_SENSOR_FEATURE_SELECTOR_ITEMS.push_back({"XI_SENSOR_FEATURE_BLACK_LEVEL_OFFSET_RAW",6, "Sensor specific register raw black level offset"});
	XI_SENSOR_FEATURE_SELECTOR_ITEMS.push_back({"XI_SENSOR_FEATURE_SHORT_INTERVAL_SHUTTER",7, "Short Interval Shutter - sensor specific feature"});
	XI_SENSOR_FEATURE_SELECTOR_ITEMS.push_back({"XI_SENSOR_FEATURE_AUTO_LOW_POWER_MODE_AUTO",8, "Sensor low power mode"});
	XI_SENSOR_FEATURE_SELECTOR_ITEMS.push_back({"XI_SENSOR_FEATURE_HIGH_CONVERSION_GAIN", 9, "Sets sensor high conversion gain"});

	// Camera sensor mode enumerator.
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD0",                            0, "Sensor mode number 0"});
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD1",                            1, "Sensor mode number 1"});
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD2",                            2, "Sensor mode number 2"});
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD3",                            3, "Sensor mode number 3"});
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD4",                            4, "Sensor mode number 4"});
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD5",                            5, "Sensor mode number 5"});
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD6",                            6, "Sensor mode number 6"});
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD7",                            7, "Sensor mode number 7"});
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD8",                            8, "Sensor mode number 8"});
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD9",                            9, "Sensor mode number 9"});
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD10",                           10, "Sensor mode number 10"});
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD11",                           11, "Sensor mode number 11"});
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD12",                           12, "Sensor mode number 12"});
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD13",                           13, "Sensor mode number 13"});
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD14",                           14, "Sensor mode number 14"});
	XI_SENSOR_MODE_ITEMS.push_back({"XI_SENS_MD15",                           15, "Sensor mode number 15"});

	// Defines image sensor area as output.
	XI_IMAGE_AREA_SELECTOR_ITEMS.push_back({"XI_IMAGE_AREA_ACTIVE",                   0, "All light sensitive pixels suggested by image vendor."});
	XI_IMAGE_AREA_SELECTOR_ITEMS.push_back({"XI_IMAGE_AREA_ACTIVE_AND_MASKED",        1, "All Active pixels plus masked pixels surrounding the Active area."});

	// Camera channel count enumerator.
	XI_SENSOR_OUTPUT_CHANNEL_COUNT_ITEMS.push_back({"XI_CHANN_CNT2",                          2, "2 sensor readout channels."});
	XI_SENSOR_OUTPUT_CHANNEL_COUNT_ITEMS.push_back({"XI_CHANN_CNT4",                          4, "4 sensor readout channels."});
	XI_SENSOR_OUTPUT_CHANNEL_COUNT_ITEMS.push_back({"XI_CHANN_CNT8",                          8, "8 sensor readout channels."});
	XI_SENSOR_OUTPUT_CHANNEL_COUNT_ITEMS.push_back({"XI_CHANN_CNT16",                         16, "16 sensor readout channels."});
	XI_SENSOR_OUTPUT_CHANNEL_COUNT_ITEMS.push_back({"XI_CHANN_CNT32",                         32, "32 sensor readout channels."});

	// Sensor defects correction list selector
	XI_SENS_DEFFECTS_CORR_LIST_SELECTOR_ITEMS.push_back({"XI_SENS_DEFFECTS_CORR_LIST_SEL_FACTORY", 0, "Factory defect correction list"});
	XI_SENS_DEFFECTS_CORR_LIST_SELECTOR_ITEMS.push_back({"XI_SENS_DEFFECTS_CORR_LIST_SEL_USER0",   1, "User defect correction list"});
	XI_SENS_DEFFECTS_CORR_LIST_SELECTOR_ITEMS.push_back({"XI_SENS_DEFFECTS_CORR_LIST_SEL_IN_CAMERA",2, "Device specific defect correction list"});

	// Acquisition status Selector
	XI_ACQUISITION_STATUS_SELECTOR_ITEMS.push_back({"XI_ACQUISITION_STATUS_ACQ_ACTIVE",       0, " Device is currently doing an acquisition of one or many frames."});

	// Select unit where data-pipe is configured
	XI_DP_UNIT_SELECTOR_ITEMS.push_back({"XI_DP_UNIT_SENSOR",                      0, "Selects device image sensor"});
	XI_DP_UNIT_SELECTOR_ITEMS.push_back({"XI_DP_UNIT_FPGA",                        1, "Selects device image FPGA"});

	// Select unit processor
	XI_DP_PROC_SELECTOR_ITEMS.push_back({"XI_DP_PROC_NONE",                        0, "Default empty processor"});
	XI_DP_PROC_SELECTOR_ITEMS.push_back({"XI_DP_PROC_CHANNEL_MUXER",               1, "Channel Muxer (selected processor combines multiple input channels)"});
	XI_DP_PROC_SELECTOR_ITEMS.push_back({"XI_DP_PROC_PIXEL_SEQUENCER",             2, "Selects pixel data output sequence"});
	XI_DP_PROC_SELECTOR_ITEMS.push_back({"XI_DP_PROC_CHANNEL_1",                   3, "Selects sensor output channel 1"});
	XI_DP_PROC_SELECTOR_ITEMS.push_back({"XI_DP_PROC_CHANNEL_2",                   4, "Selects sensor output channel 2"});
	XI_DP_PROC_SELECTOR_ITEMS.push_back({"XI_DP_PROC_FRAME_BUFFER",                5, "Selects frame buffer memory"});

	// Select processor parameter
	XI_DP_PARAM_SELECTOR_ITEMS.push_back({"XI_DP_PARAM_NONE",                       0, "Empty parameter"});
	XI_DP_PARAM_SELECTOR_ITEMS.push_back({"XI_DP_PARAM_CHMUX_CHANNEL_SELECTOR",     1, "Defines output of Channel Muxer processor"});
	XI_DP_PARAM_SELECTOR_ITEMS.push_back({"XI_DP_PARAM_CHMUX_ALPHA",                2, "Channel merger coefficient Alpha"});
	XI_DP_PARAM_SELECTOR_ITEMS.push_back({"XI_DP_PARAM_CHMUX_BETA",                 3, "Channel merger coefficient Beta"});
	XI_DP_PARAM_SELECTOR_ITEMS.push_back({"XI_DP_PARAM_PIXSEQ_SELECTOR",            4, "PixSeq Selector"});
	XI_DP_PARAM_SELECTOR_ITEMS.push_back({"XI_DP_PARAM_CHANNEL_TIMING",             5, "Selected channel timing"});
	XI_DP_PARAM_SELECTOR_ITEMS.push_back({"XI_DP_PARAM_FRAMEBUF_MODE",              6, "Frame Buffer Mode"});
	XI_DP_PARAM_SELECTOR_ITEMS.push_back({"XI_DP_PARAM_FRAMEBUF_SIZE",              7, "Frame Buffer Size Bytes"});

	// Select processor parameter value
	XI_DP_PARAM_VALUE_ITEMS.push_back({"XI_DP_PARAM_VALUE_CHMUX_CHANNEL_1",      0, "Selected source channel 1"});
	XI_DP_PARAM_VALUE_ITEMS.push_back({"XI_DP_PARAM_VALUE_CHMUX_CHANNEL_2",      1, "Selected source channel 2"});
	XI_DP_PARAM_VALUE_ITEMS.push_back({"XI_DP_PARAM_VALUE_CHMUX_CHANNEL_1_2",    2, "Selected source channel 1 and 2"});
	XI_DP_PARAM_VALUE_ITEMS.push_back({"XI_DP_PARAM_VALUE_CHMUX_MERGED",         3, "Merged data of two channels"});
	XI_DP_PARAM_VALUE_ITEMS.push_back({"XI_DP_PARAM_VALUE_CHMUX_CMS_S",          4, "Correlated Multiple Sampling(summing)"});
	XI_DP_PARAM_VALUE_ITEMS.push_back({"XI_DP_PARAM_VALUE_PIXSEQ_ONE_VALUE",     5, "Output is one value per pixel"});
	XI_DP_PARAM_VALUE_ITEMS.push_back({"XI_DP_PARAM_VALUE_PIXSEQ_TWO_VALUES",    6, "Output are two values per pixel"});
	XI_DP_PARAM_VALUE_ITEMS.push_back({"XI_DP_PARAM_VALUE_CHTIM_HG",             7, "High Gain channel timing"});
	XI_DP_PARAM_VALUE_ITEMS.push_back({"XI_DP_PARAM_VALUE_CHTIM_LG",             8, "Low Gain channel timing"});
	XI_DP_PARAM_VALUE_ITEMS.push_back({"XI_DP_PARAM_VALUE_FRAMEBUF_MODE_DISABLED",9, "Frame buffer is disabled"});
	XI_DP_PARAM_VALUE_ITEMS.push_back({"XI_DP_PARAM_VALUE_FRAMEBUF_MODE_ENABLED",10, "Frame buffer is on"});
	XI_DP_PARAM_VALUE_ITEMS.push_back({"XI_DP_PARAM_VALUE_PIXSEQ_FOUR_VALUES",   11, "Output are four values per pixel"});
	XI_DP_PARAM_VALUE_ITEMS.push_back({"XI_DP_PARAM_VALUE_CHMUX_CMS_A",          12, "Correlated Multiple Sampling(averaging)"});

	// User Set selector options.
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_12_STD_L",                         10, "12bit per channel STD Low Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_12_STD_H",                         11, "12bit per channel STD High Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_14_STD_L",                         12, "14bit per channel STD Low Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_NONE",                             999, "No preset selected."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_14_STD_H",                         13, "14bit per channel STD High Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_2_12_CMS_S_L",                     14, "12bit per channel, 2 samples,  CMS(summing) Low Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_2_12_CMS_S_H",                     15, "12bit per channel, 2 samples,  CMS(summing) High Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_2_14_CMS_S_L",                     16, "14bit per channel, 2 samples,  CMS(summing) Low Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_2_14_CMS_S_H",                     17, "14bit per channel, 2 samples,  CMS(summing) High Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_4_12_CMS_S_L",                     18, "12bit per channel, 4 samples,  CMS(summing) Low Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_4_12_CMS_S_H",                     19, "12bit per channel, 4 samples,  CMS(summing) High Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_4_14_CMS_S_L",                     20, "14bit per channel, 4 samples,  CMS(summing) Low Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_4_14_CMS_S_H",                     21, "14bit per channel, 4 samples,  CMS(summing) High Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_2_12_HDR_HL",                      22, "12bit per channel, 2 samples,  HDR High Low Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_2_12_HDR_L",                       23, "12bit per channel, 2 samples,  HDR Low Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_2_12_HDR_H",                       24, "12bit per channel, 2 samples,  HDR High Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_4_12_CMS_HDR_HL",                  25, "12bit per channel, 4 samples,  CMS + HDR High Low Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_2_14_HDR_L",                       26, "14bit per channel, 2 samples,  HDR Low Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_2_14_HDR_H",                       27, "14bit per channel, 2 samples,  HDR High Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_2_12_CMS_A_L",                     28, "12bit per channel, 2 samples,  CMS(averaging) Low Gain mode preset."});
	XI_USER_SET_SELECTOR_ITEMS.push_back({"XI_US_2_12_CMS_A_H",                     29, "12bit per channel, 2 samples,  CMS(averaging) High Gain mode preset."});

	// Mode of DualADC feature
	XI_DUAL_ADC_MODE_ITEMS.push_back({"XI_DUAL_ADC_MODE_OFF",                   0, "Disable DualADC feature"});
	XI_DUAL_ADC_MODE_ITEMS.push_back({"XI_DUAL_ADC_MODE_COMBINED",              1, "Set Combined mode"});
	XI_DUAL_ADC_MODE_ITEMS.push_back({"XI_DUAL_ADC_MODE_NON_COMBINED",          2, "Set NonCombined mode"});


	XI_RET_ITEMS.push_back({"XI_OK",                              0, " Function call succeeded"});
	XI_RET_ITEMS.push_back({"XI_INVALID_HANDLE",                  1, " Invalid handle"});
	XI_RET_ITEMS.push_back({"XI_READREG",                         2, " Register read error"});
	XI_RET_ITEMS.push_back({"XI_WRITEREG",                        3, " Register write error"});
	XI_RET_ITEMS.push_back({"XI_FREE_RESOURCES",                  4, " Freeing resources error"});
	XI_RET_ITEMS.push_back({"XI_FREE_CHANNEL",                    5, " Freeing channel error"});
	XI_RET_ITEMS.push_back({"XI_FREE_BANDWIDTH",                  6, " Freeing bandwith error"});
	XI_RET_ITEMS.push_back({"XI_READBLK",                         7, " Read block error"});
	XI_RET_ITEMS.push_back({"XI_WRITEBLK",                        8, " Write block error"});
	XI_RET_ITEMS.push_back({"XI_NO_IMAGE",                        9, " No image"});
	XI_RET_ITEMS.push_back({"XI_TIMEOUT",                        10, " Timeout"});
	XI_RET_ITEMS.push_back({"XI_INVALID_ARG",                    11, " Invalid arguments supplied"});
	XI_RET_ITEMS.push_back({"XI_NOT_SUPPORTED",                  12, " Not supported"});
	XI_RET_ITEMS.push_back({"XI_ISOCH_ATTACH_BUFFERS",           13, " Attach buffers error"});
	XI_RET_ITEMS.push_back({"XI_GET_OVERLAPPED_RESULT",          14, " Overlapped result"});
	XI_RET_ITEMS.push_back({"XI_MEMORY_ALLOCATION",              15, " Memory allocation error"});
	XI_RET_ITEMS.push_back({"XI_DLLCONTEXTISNULL",               16, " DLL context is NULL"});
	XI_RET_ITEMS.push_back({"XI_DLLCONTEXTISNONZERO",            17, " DLL context is non zero"});
	XI_RET_ITEMS.push_back({"XI_DLLCONTEXTEXIST",                18, " DLL context exists"});
	XI_RET_ITEMS.push_back({"XI_TOOMANYDEVICES",                 19, " Too many devices connected"});
	XI_RET_ITEMS.push_back({"XI_ERRORCAMCONTEXT",                20, " Camera context error"});
	XI_RET_ITEMS.push_back({"XI_UNKNOWN_HARDWARE",               21, " Unknown hardware"});
	XI_RET_ITEMS.push_back({"XI_INVALID_TM_FILE",                22, " Invalid TM file"});
	XI_RET_ITEMS.push_back({"XI_INVALID_TM_TAG",                 23, " Invalid TM tag"});
	XI_RET_ITEMS.push_back({"XI_INCOMPLETE_TM",                  24, " Incomplete TM"});
	XI_RET_ITEMS.push_back({"XI_BUS_RESET_FAILED",               25, " Bus reset error"});
	XI_RET_ITEMS.push_back({"XI_NOT_IMPLEMENTED",                26, " Not implemented"});
	XI_RET_ITEMS.push_back({"XI_SHADING_TOOBRIGHT",              27, " Shading is too bright"});
	XI_RET_ITEMS.push_back({"XI_SHADING_TOODARK",                28, " Shading is too dark"});
	XI_RET_ITEMS.push_back({"XI_TOO_LOW_GAIN",                   29, " Gain is too low"});
	XI_RET_ITEMS.push_back({"XI_INVALID_BPL",                    30, " Invalid sensor defect correction list"});
	XI_RET_ITEMS.push_back({"XI_BPL_REALLOC",                    31, " Error while sensor defect correction list reallocation"});
	XI_RET_ITEMS.push_back({"XI_INVALID_PIXEL_LIST",             32, " Invalid pixel list"});
	XI_RET_ITEMS.push_back({"XI_INVALID_FFS",                    33, " Invalid Flash File System"});
	XI_RET_ITEMS.push_back({"XI_INVALID_PROFILE",                34, " Invalid profile"});
	XI_RET_ITEMS.push_back({"XI_INVALID_CALIBRATION",            35, " Invalid calibration"});
	XI_RET_ITEMS.push_back({"XI_INVALID_BUFFER",                 36, " Invalid buffer"});
	XI_RET_ITEMS.push_back({"XI_INVALID_DATA",                   38, " Invalid data"});
	XI_RET_ITEMS.push_back({"XI_TGBUSY",                         39, " Timing generator is busy"});
	XI_RET_ITEMS.push_back({"XI_IO_WRONG",                       40, " Wrong operation open/write/read/close"});
	XI_RET_ITEMS.push_back({"XI_ACQUISITION_ALREADY_UP",         41, " Acquisition already started"});
	XI_RET_ITEMS.push_back({"XI_OLD_DRIVER_VERSION",             42, " Old version of device driver installed to the system."});
	XI_RET_ITEMS.push_back({"XI_GET_LAST_ERROR",                 43, " To get error code please call GetLastError function."});
	XI_RET_ITEMS.push_back({"XI_CANT_PROCESS",                   44, " Data cannot be processed"});
	XI_RET_ITEMS.push_back({"XI_ACQUISITION_STOPED",             45, " Acquisition is stopped. It needs to be started to perform operation."});
	XI_RET_ITEMS.push_back({"XI_ACQUISITION_STOPED_WERR",        46, " Acquisition has been stopped with an error."});
	XI_RET_ITEMS.push_back({"XI_INVALID_INPUT_ICC_PROFILE",      47, " Input ICC profile missing or corrupted"});
	XI_RET_ITEMS.push_back({"XI_INVALID_OUTPUT_ICC_PROFILE",     48, " Output ICC profile missing or corrupted"});
	XI_RET_ITEMS.push_back({"XI_DEVICE_NOT_READY",               49, " Device not ready to operate"});
	XI_RET_ITEMS.push_back({"XI_SHADING_TOOCONTRAST",            50, " Shading is too contrast"});
	XI_RET_ITEMS.push_back({"XI_ALREADY_INITIALIZED",            51, " Module already initialized"});
	XI_RET_ITEMS.push_back({"XI_NOT_ENOUGH_PRIVILEGES",          52, " Application does not have enough privileges (one or more app)"});
	XI_RET_ITEMS.push_back({"XI_NOT_COMPATIBLE_DRIVER",          53, " Installed driver is not compatible with current software"});
	XI_RET_ITEMS.push_back({"XI_TM_INVALID_RESOURCE",            54, " TM file was not loaded successfully from resources"});
	XI_RET_ITEMS.push_back({"XI_DEVICE_HAS_BEEN_RESETED",        55, " Device has been reset, abnormal initial state"});
	XI_RET_ITEMS.push_back({"XI_NO_DEVICES_FOUND",               56, " No Devices Found"});
	XI_RET_ITEMS.push_back({"XI_RESOURCE_OR_FUNCTION_LOCKED",    57, " Resource (device) or function locked by mutex"});
	XI_RET_ITEMS.push_back({"XI_BUFFER_SIZE_TOO_SMALL",          58, " Buffer provided by user is too small"});
	XI_RET_ITEMS.push_back({"XI_COULDNT_INIT_PROCESSOR",         59, " Could not initialize processor."});
	XI_RET_ITEMS.push_back({"XI_NOT_INITIALIZED",                60, " The object/module/procedure/process being referred to has not been started."});
	XI_RET_ITEMS.push_back({"XI_RESOURCE_NOT_FOUND",             61, " Resource not found(could be processor, file, item...)."});
	XI_RET_ITEMS.push_back({"XI_UNKNOWN_PARAM",                  100, " Unknown parameter"});
	XI_RET_ITEMS.push_back({"XI_WRONG_PARAM_VALUE",              101, " Wrong parameter value"});
	XI_RET_ITEMS.push_back({"XI_WRONG_PARAM_TYPE",               103, " Wrong parameter type"});
	XI_RET_ITEMS.push_back({"XI_WRONG_PARAM_SIZE",               104, " Wrong parameter size"});
	XI_RET_ITEMS.push_back({"XI_BUFFER_TOO_SMALL",               105, " Input buffer is too small"});
	XI_RET_ITEMS.push_back({"XI_NOT_SUPPORTED_PARAM",            106, " Parameter is not supported"});
	XI_RET_ITEMS.push_back({"XI_NOT_SUPPORTED_PARAM_INFO",       107, " Parameter info not supported"});
	XI_RET_ITEMS.push_back({"XI_NOT_SUPPORTED_DATA_FORMAT",      108, " Data format is not supported"});
	XI_RET_ITEMS.push_back({"XI_READ_ONLY_PARAM",                109, " Read only parameter"});
	XI_RET_ITEMS.push_back({"XI_BANDWIDTH_NOT_SUPPORTED",        111, " This camera does not support currently available bandwidth"});
	XI_RET_ITEMS.push_back({"XI_INVALID_FFS_FILE_NAME",          112, " FFS file selector is invalid or NULL"});
	XI_RET_ITEMS.push_back({"XI_FFS_FILE_NOT_FOUND",             113, " FFS file not found"});
	XI_RET_ITEMS.push_back({"XI_PARAM_NOT_SETTABLE",             114, " Parameter value cannot be set (might be out of range or invalid)."});
	XI_RET_ITEMS.push_back({"XI_SAFE_POLICY_NOT_SUPPORTED",      115, " Safe buffer policy is not supported. E.g. when transport target is set to GPU (GPUDirect)."});
	XI_RET_ITEMS.push_back({"XI_GPUDIRECT_NOT_AVAILABLE",        116, " GPUDirect is not available. E.g. platform isn't supported or CUDA toolkit isn't installed."});
	XI_RET_ITEMS.push_back({"XI_INCORRECT_SENS_ID_CHECK",        117, " Incorrect sensor board unique identifier checksum."});
	XI_RET_ITEMS.push_back({"XI_INCORRECT_FPGA_TYPE",            118, " Incorrect or unknown FPGA firmware type used for camera."});
	XI_RET_ITEMS.push_back({"XI_PARAM_CONDITIONALLY_NOT_AVAILABLE",119, " Parameter is not available in current context. Available only if another feature is turned on."});
	XI_RET_ITEMS.push_back({"XI_PROC_OTHER_ERROR",               201, " Processing error - other"});
	XI_RET_ITEMS.push_back({"XI_PROC_PROCESSING_ERROR",          202, " Error while image processing."});
	XI_RET_ITEMS.push_back({"XI_PROC_INPUT_FORMAT_UNSUPPORTED",  203, " Input format is not supported for processing."});
	XI_RET_ITEMS.push_back({"XI_PROC_OUTPUT_FORMAT_UNSUPPORTED", 204, " Output format is not supported for processing."});
	XI_RET_ITEMS.push_back({"XI_OUT_OF_RANGE",                   205, " Parameter value is out of range"});
		
}


xiAPIplus_Enumerators::param_item_t::param_item_t()
{
	name = NULL;
	value = 0;
	description = NULL;
}

xiAPIplus_Enumerators::param_item_t::param_item_t(const char * in_name, int in_value, const char * in_description)
{
	name = in_name;
	value = in_value;
	description = in_description;
}

xiAPIplus_Enumerators::param_item_t * xiAPIplus_Enumerators::FindItem(std::vector<param_item_t> * param_vector, int item_val)
{
	for (unsigned int i=0;i<param_vector->size();i++)
	{
		if ((*param_vector)[i].value==item_val)
		{			
			return &((*param_vector)[i]);
		}
	}
	return NULL;
}
//-------------------------------------------------------------------------------------------------------------------
// xiAPIplus implementation file
// XIMEA Application Programming Interface Object Oriented Approach
//-------------------------------------------------------------------------------------------------------------------

//#include <os_common_header.h>
//#include <stdio.h>
//#include <cstring>
//#include <xiAPIplus/xiapiplus.h>

#ifdef WIN32
// disable warning C4996: 'sprintf': This function or variable may be unsafe - use _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif

// forward declarations

void ReportException(XI_RETURN res, const char* location);

// -----------------------------------------------
// parameters handlers implementation
// -----------------------------------------------

//#include "xiAPIplus_parameters.cpp"

// -----------------------------------------------
// xiAPIplus
// -----------------------------------------------

unsigned long xiAPIplus::GetNumberOfConnectedCameras()
{
	DWORD count=0;
	XI_RETURN res=xiGetNumberDevices(&count);
	if (res) ReportException(res,"GetNumberOfConnectedCameras");
	return count;
}

#if 0
// -----------------------------------------------
// general parametes interface
// working with set of parameters
// -----------------------------------------------

void xiAPIplus_Camera_Parameters::Save_to_File(char* filename);
void xiAPIplus_Camera_Parameters::Load_from_File(char* filename);
void xiAPIplus_Camera_Parameters::Save_to_Preset(int id);
void xiAPIplus_Camera_Parameters::Load_from_Preset(int id);
int xiAPIplus_Camera_Parameters::Get_Count();
void xiAPIplus_Camera_Parameters::Get_Name(int id, char* name, int name_max_size);
void xiAPIplus_Camera_Parameters::Get_Value(int id, char* value, int value_max_size);
void xiAPIplus_Camera_Parameters::Set_Value(int id, char* value);

#endif // 0

// exception handling
void ReportException(XI_RETURN res, const char* location)
{
	// generate exception
	char descr[200]="(missing_error_description)";
	int total_errors=sizeof(xiAPIplus_errorcodes_list)/sizeof(xiapi_errorcode_t);
	// find description
	for(int i=0;i<total_errors;i++)
	{
		if (xiAPIplus_errorcodes_list[i].code == res)
		{
			// found
			const char* d=xiAPIplus_errorcodes_list[i].descr;
			if (sizeof(descr) > strlen(d) + sizeof("%s (xiAPIplus_Camera::%s)") + strlen(location))
			{
				sprintf(descr,"%s (xiAPIplus_Camera::%s)",xiAPIplus_errorcodes_list[i].descr,location);
			}
			else
			{
				strcpy(descr,"(descr_too_long)");
			}
			break;
		}
	}
	throw xiAPIplus_Exception(res, descr);
}

void xiAPIplus_Camera::CheckResult(XI_RETURN res, const char* location)
{
	xiAPIPlusDP((DBFOUT "%d\n",res));
	if (res != XI_OK)
	{
		ReportException(res, location);
	}
}

void xiAPIplus_Camera::CheckResultParam(XI_RETURN res, const char* location, const char* param)
{
	xiAPIPlusDP((DBFOUT "%d\n",res));
	if (res != XI_OK)
	{
		char buff[MAX_PATH] = "";
		sprintf(buff, "%s - %s", location, param);
		ReportException(res, buff);
	}
}

void xiAPIplus_Exception::GetDescription(char* name, size_t name_max_size)
{
	if (!name) return;
	if (!description) return;
	if (name_max_size<sizeof(description)) return;
	strncpy(name,description,name_max_size);
}

void xiAPIplus_Exception::PrintError()
{
	char descr[200]="";
	GetDescription(descr,sizeof(descr)-1);
	printf("xiAPIplus-Error %d:%s\n",GetErrorNumber(),descr);
}

unsigned long xiAPIplus_Camera::GetNumberOfConnectedCameras()
{
	xiAPIplus api;
	return api.GetNumberOfConnectedCameras();
}

// -----------------------------------------------
// class xiAPIplus - Image
// -----------------------------------------------

xiAPIplus_Image::xiAPIplus_Image()
{
	memset(&image,0,sizeof(image));
	image.size = sizeof(image);
	is_copy = false;
}

// -----------------------------------------------
// class xiAPIplus - Camera
// -----------------------------------------------

xiAPIplus_Camera::xiAPIplus_Camera()
{
	camera_handle=NULL;
	image_timeout_ms=1000;
	acquisition_active=false;
	is_debug_enabled=false;
}

xiAPIplus_Camera::~xiAPIplus_Camera()
{
	Close();
}

void xiAPIplus_Camera::OpenFirst()
{
	OpenByID(0);
}

void xiAPIplus_Camera::OpenByID(const unsigned long id)
{
	xiAPIPlusDP((DBFIN "%s\n","OpenByID"));
	XI_RETURN res=xiOpenDevice(id, &camera_handle);
	CheckResult(res,"OpenByID");

	if(!camera_handle) res = XI_INVALID_HANDLE;
	CheckResult(res,"OpenByID");
}
void xiAPIplus_Camera::OpenBySN(const char* serial_number)
{
	if (!serial_number)  ReportException(XI_WRONG_PARAM_VALUE, "xiAPIplus_Camera::OpenBySN()");

	xiAPIPlusDP((DBFIN "%s\n", "OpenBySN"));
	XI_RETURN res = xiOpenDeviceBy(XI_OPEN_BY_SN, serial_number, &camera_handle);
	CheckResult(res, "OpenBySN");

	if (!camera_handle) res = XI_INVALID_HANDLE;
	CheckResult(res, "OpenBySN");
}

void xiAPIplus_Camera::OpenByPath(const char* device_path)
{
	if(!device_path)  ReportException(XI_WRONG_PARAM_VALUE, "xiAPIplus_Camera::OpenByPath()");

	xiAPIPlusDP((DBFIN "%s\n","OpenByPath"));
	XI_RETURN res=xiOpenDeviceBy(XI_OPEN_BY_INST_PATH, device_path, &camera_handle);
	CheckResult(res,"OpenByPath");

	if(!camera_handle) res = XI_INVALID_HANDLE;
	CheckResult(res,"OpenByPath");
}

void xiAPIplus_Camera::OpenByUserID(const char* user_id)
{
	if(!user_id)  ReportException(XI_WRONG_PARAM_VALUE, "xiAPIplus_Camera::OpenByUserID()");

	xiAPIPlusDP((DBFIN "%s\n","OpenByUserID"));
	XI_RETURN res=xiOpenDeviceBy(XI_OPEN_BY_USER_ID, user_id, &camera_handle);
	CheckResult(res,"OpenByUserID");

	if(!camera_handle) res = XI_INVALID_HANDLE;
	CheckResult(res,"OpenByUserID");
}

void xiAPIplus_Camera::OpenByLocation(const char* location)
{
	if(!location)  ReportException(XI_WRONG_PARAM_VALUE, "xiAPIplus_Camera::OpenByLocation()");

	xiAPIPlusDP((DBFIN "%s\n","OpenByUserID"));
	XI_RETURN res=xiOpenDeviceBy(XI_OPEN_BY_LOC_PATH, location, &camera_handle);
	CheckResult(res,"OpenByLocation");

	if(!camera_handle) res = XI_INVALID_HANDLE;
	CheckResult(res,"OpenByLocation");
}

// ---------------------------------------------------------------------
// camera close

void xiAPIplus_Camera::Close()
{
	xiAPIPlusDP((DBFIN "%s\n","Close"));
	if (camera_handle)
	{
		XI_RETURN res=xiCloseDevice(camera_handle);
		CheckResult(res,"Close");
	}
	camera_handle=NULL;
}

// ---------------------------------------------------------------------
// acquisition
void xiAPIplus_Camera::StartAcquisition()
{
	CheckCamHandle("StartAcquisition");
	XI_RETURN res=xiStartAcquisition(camera_handle);
	CheckResult(res,"StartAcquisition");
	acquisition_active=true;
}

void xiAPIplus_Camera::StopAcquisition()
{
	CheckCamHandle("StopAcquisition");
	XI_RETURN res=xiStopAcquisition(camera_handle);
	CheckResult(res,"StopAcquisition");
	acquisition_active=false;
}

bool xiAPIplus_Camera::IsAcquisitionActive()
{
	return acquisition_active;
}

// ---------------------------------------------------------------------
// get next image
// receiving next image from xiAPI
// if (app_image is defined) storing result to app_image
// else storing result to last_image, also returing pointer to it

xiAPIplus_Image* xiAPIplus_Camera::GetNextImage(xiAPIplus_Image* app_image)
{
	CheckCamHandle("GetNextImage");
	xiAPIplus_Image* image=&last_image;
	if (app_image)
		image = app_image;

	XI_RETURN res = XI_OK;
	res = xiGetImage(camera_handle, image_timeout_ms, image->GetXI_IMG());
	CheckResult(res,"GetNextImage");
	return image;
}

// ---------------------------------------------------------------------
// get last received image
// returns last received image (by function GetNextImage)

xiAPIplus_Image* xiAPIplus_Camera::GetLastImage()
{
	return &last_image;
}

// ---------------------------------------------------------------------
// set next image timeout in milliseconds

void xiAPIplus_Camera::SetNextImageTimeout_ms(int timeout_ms)
{
	image_timeout_ms=timeout_ms;
}

// ---------------------------------------------------------------------
// get next image timeout in milliseconds

int xiAPIplus_Camera::GetNextImageTimeout_ms()
{
	return image_timeout_ms;
}

// ---------------------------------------------------------------------
// return xiAPI parameter by name

void xiAPIplus_Camera::GetXIAPIParamString(char* xiapi_param_name, char* value, int value_max_size)
{
	CheckCamHandle("GetXIAPIParamStr");
	XI_RETURN res=xiGetParamString(camera_handle, xiapi_param_name, value, value_max_size);
	CheckResultParam(res,"GetXIAPIParamStr", xiapi_param_name);
}

void xiAPIplus_Camera::SetXIAPIParamString(char* xiapi_param_name, char* value, unsigned int value_max_size)
{
	CheckCamHandle("SetXIAPIParamStr");
	XI_RETURN res=xiSetParamString(camera_handle, xiapi_param_name, value, value_max_size);
	CheckResultParam(res,"SetXIAPIParamStr", xiapi_param_name);
}

void xiAPIplus_Camera::GetXIAPIParamInt(char* xiapi_param_name, int* value)
{
	CheckCamHandle("GetXIAPIParamInt");
	XI_RETURN res=xiGetParamInt(camera_handle, xiapi_param_name, value);
	CheckResultParam(res,"GetXIAPIParamInt", xiapi_param_name);
}
void xiAPIplus_Camera::SetXIAPIParamInt(char* xiapi_param_name, int value)
{
	CheckCamHandle("SetXIAPIParamInt");
	XI_RETURN res=xiSetParamInt(camera_handle, xiapi_param_name, value);
	CheckResultParam(res,"SetXIAPIParamInt", xiapi_param_name);
}

void xiAPIplus_Camera::GetXIAPIParamFloat(char* xiapi_param_name, float* value)
{
	CheckCamHandle("GetXIAPIParamFloat");
	XI_RETURN res=xiGetParamFloat(camera_handle, xiapi_param_name, value);
	CheckResultParam(res,"GetXIAPIParamFloat", xiapi_param_name);
}

void xiAPIplus_Camera::SetXIAPIParamFloat(char* xiapi_param_name, float value)
{
	CheckCamHandle("SetXIAPIParamFloat");
	XI_RETURN res=xiSetParamFloat(camera_handle, xiapi_param_name, value);
	CheckResultParam(res,"SetXIAPIParamFloat", xiapi_param_name);
}

void xiAPIplus_Camera::SetXIAPIParam(char* xiapi_param_name, void* value, size_t value_size, XI_PRM_TYPE type)
{
	CheckCamHandle("SetXIAPIParam");
	XI_RETURN res=xiSetParam(camera_handle, xiapi_param_name, value, (DWORD)value_size,type);
	CheckResultParam(res,"SetXIAPIParam", xiapi_param_name);
}

void xiAPIplus_Camera::GetXIAPIParam(char* xiapi_param_name, void* value, size_t * value_size, XI_PRM_TYPE * type)
{
	CheckCamHandle("GetXIAPIParam");
	XI_RETURN res=xiGetParam(camera_handle, xiapi_param_name, value, (DWORD*)value_size,type);
	CheckResultParam(res,"GetXIAPIParam", xiapi_param_name);
}

// ---------------------------------------------------------------------
// Image Destructor

xiAPIplus_Image::~xiAPIplus_Image()
{
	if (IsCopy())
	{
		// desctruct copy
		XI_IMG* image=GetXI_IMG();
		if (image->bp && GetPixelsArraySize())
		{
			if(image->bp)
				free(image->bp);
		}
	}
}

// ---------------------------------------------------------------------
// get bytes per pixel

int xiAPIplus_Image::GetBytesPerPixel()
{
	int bpp=1;
	switch (image.frm)
	{
	case XI_MONO8:
	case XI_RAW8:
	case XI_RAW8X2:
	case XI_RAW8X4:
	case XI_RGB_PLANAR:
		bpp=1;
		break;
	case XI_MONO16:
	case XI_RAW16:
	case XI_RAW16X2:
	case XI_RAW16X4:
	case XI_RGB16_PLANAR:
		bpp=2;
		break;
	case XI_RGB24:
		bpp=3;
		break;
	case XI_RAW32:
	case XI_RGB32:
	case XI_RAW32FLOAT:
		bpp=4;
		break;
	case XI_RGB48:
		bpp = 6;
		break;
	case XI_RGB64:
		bpp = 8;
		break;
	default:
		ReportException(XI_NOT_SUPPORTED_DATA_FORMAT, "GetBytesPerPixel");
		break;
	}
	return bpp;
}

// ---------------------------------------------------------------------

int xiAPIplus_Image::GetBitCount()
{
	int vals=1;
	switch (image.frm)
	{
	case XI_MONO8:
	case XI_RAW8:
	case XI_RAW8X2:
	case XI_RAW8X4:
	case XI_RGB_PLANAR:	vals = 8; break;
	case XI_MONO16:
	case XI_RAW16:
	case XI_RAW16X2:
	case XI_RAW16X4:
	case XI_RGB16_PLANAR: vals = 16; break;
	case XI_RGB24:		vals = 24; break;
	case XI_RAW32:
	case XI_RGB32:
	case XI_RAW32FLOAT:	vals = 32; break;
	case XI_RGB48:		vals = 48; break;
	case XI_RGB64:		vals = 64; break;
	default:
		ReportException(XI_NOT_SUPPORTED_DATA_FORMAT, "GetBitCount");
		break;
	}
	return vals;
}

// ---------------------------------------------------------------------
// Image Clone
// make new copy of existing image
// this copy should be deleted by caller after finishing of use

void xiAPIplus_Image::CopyTo(xiAPIplus_Image* image_copy)
{
	XI_IMG* orig=GetXI_IMG();
	XI_IMG* clone=image_copy->GetXI_IMG();
	// copy structure
	memcpy(clone,orig,sizeof(XI_IMG));
	// copy image data
	clone->bp = malloc(GetPixelsArraySize());
	if (!clone->bp)
	{
		ReportException(XI_MEMORY_ALLOCATION, "CopyTo");
	}else memcpy(clone->bp, orig->bp, GetPixelsArraySize());
}

// ---------------------------------------------------------------------
// return core xiAPI image

XI_IMG* xiAPIplus_Image::GetXI_IMG()
{
	return &image;
}

// ---------------------------------------------------------------------

int xiAPIplus_Image::GetPadding_X()
{
	switch(image.frm)
	{
	case XI_RAW16:
	case XI_MONO16:
		return image.padding_x/2;
	default:
		return image.padding_x;
	}
}

// ---------------------------------------------------------------------

xiAPIplus_ImageProcessing::xiAPIplus_ImageProcessing()
{
	processing_handle_ = NULL;
	XI_RETURN res=xiProcOpen(&processing_handle_);
	CheckResult(res,"xiProcOpen");
}

// ---------------------------------------------------------------------

xiAPIplus_ImageProcessing::~xiAPIplus_ImageProcessing()
{
	XI_RETURN res=xiProcClose(processing_handle_);
	CheckResult(res,"xiProcClose");
}

// ---------------------------------------------------------------------

void xiAPIplus_ImageProcessing::CheckResult(XI_RETURN res, const char* location)
{
	if (res != XI_OK)
	{
		ReportException(res, location);
	}
}

// -------------------------------------------------------------------

void xiAPIplus_ImageProcessing::SetParam(const char* prm, void* val, DWORD size, XI_PRM_TYPE type)
{
	XI_RETURN res=xiProcSetParam(processing_handle_,prm,val,size,type);
	CheckResult(res,"xiProcSetParam");
}

// ---------------------------------------------------------------------

void xiAPIplus_ImageProcessing::PushImage(unsigned char* first_pixel)
{
	XI_RETURN res=xiProcPushImage(processing_handle_,first_pixel);
	CheckResult(res,"xiProcPushImage");
}

// ---------------------------------------------------------------------

void xiAPIplus_ImageProcessing::PullImage()
{
	XI_RETURN res=xiProcPullImage(processing_handle_,0, last_image_.GetXI_IMG());
	CheckResult(res,"xiPullImage");
}

// ---------------------------------------------------------------------

void xiAPIplus_ImageProcessing::GetImage(xiAPIplus_Image* ret_image)
{
	last_image_.CopyTo(ret_image);
}

// ---------------------------------------------------------------------
//#include "XiSampleOpencv.hpp"




/**********************************************************************************/
/**
* Initialize the xiAPIplusCameraOcv class.
*/
xiAPIplusCameraOcv::xiAPIplusCameraOcv(){
	cv_mat_image_ = cv::Mat(0,1,CV_8UC1);
	next_image_ = NULL;
	counter_=0;
	index_=0;
}

/**********************************************************************************/
/**
* Class destructor. Free allocated memory, release images
*/
xiAPIplusCameraOcv::~xiAPIplusCameraOcv(){
	printf("Closing xiAPIplus_Ocv camera\n");
	cv_mat_image_.release();
}

/**********************************************************************************/
/**
* Reads an image from the camera using XiAPI, stores the image in OpenCV Mat format.
* @return OpenCV Mat image. 
*/
cv::Mat xiAPIplusCameraOcv::GetNextImageOcvMat(){
	next_image_ = GetNextImage(NULL);
	return ConvertOcvMat(next_image_);
}

/**********************************************************************************/
/**
* Converts a XiAPI image (xiAPIplus_Image*) to OpenCV  .
* @param input_image[in] Input xiAPIplus_Image* to be converted.
* @return converted OpenCV Mat. 
*/
cv::Mat	xiAPIplusCameraOcv::ConvertOcvMat(xiAPIplus_Image *  input_image){
	counter_++;
	next_image_ = input_image;
	// update cvImage after format has changed
	resetCvImage_();
	// allocate frame buffer copy pixel data
	cv_mat_image_.data = (uchar*)input_image->GetPixels();

	if (cv_mat_image_.empty()) printf("Error: converting XI_IMG to Mat\n");
	return cv_mat_image_;
}

/**********************************************************************************/
/**
* Resets the Opencv image if properties of XI_IMG have changed. Resets the cv_mat_image_.
*/
void xiAPIplusCameraOcv::resetCvImage_()
{
	bool do_reset = false;

	// first check basic image resolution
	switch (next_image_->GetDataFormat())
	{
		case XI_MONO8:
		{
			if (((int)(next_image_->GetWidth() + next_image_->GetPadding_X()) != cv_mat_image_.cols) || ((int)next_image_->GetHeight() != cv_mat_image_.rows))
				do_reset = true;
		}
		break;
		case XI_RGB_PLANAR:
		case XI_RGB16_PLANAR:
		{
			if (((int)next_image_->GetWidth() != cv_mat_image_.cols) || (((int)next_image_->GetHeight() * 3) != cv_mat_image_.rows))
				do_reset = true;
		}
		break;
		case XI_RAW8X2:
		case XI_RAW16X2:
		{
			if ((((int)next_image_->GetWidth() *2) != cv_mat_image_.cols) || ((int)next_image_->GetHeight() != cv_mat_image_.rows))
				do_reset = true;
		}
		break;
		case XI_RAW8X4:
		case XI_RAW16X4:
		{
			if ((((int)next_image_->GetWidth() *4) != cv_mat_image_.cols) || ((int)next_image_->GetHeight() != cv_mat_image_.rows))
				do_reset = true;
		}
		break;
		default:
		{
			if (((int)next_image_->GetWidth() != cv_mat_image_.cols) || ((int)next_image_->GetHeight() != cv_mat_image_.rows))
				do_reset = true;
		}
	}

	// afterwards check image format
	switch( next_image_->GetDataFormat())
	{
		case XI_MONO8		:
		case XI_RAW8        :
		case XI_RAW8X2		:
		case XI_RAW8X4		:
		case XI_RGB_PLANAR	:
		{
			if (cv_mat_image_.type() != CV_8UC1)
				do_reset = true;
		}
		break;
		case XI_MONO16			:
		case XI_RAW16			:
		case XI_RAW16X2			:
		case XI_RAW16X4			:
		case XI_RGB16_PLANAR	:
		{
			if (cv_mat_image_.type() != CV_16UC1)
				do_reset = true;
		}
		break;
		case XI_RGB24       :
		{ 
			if (cv_mat_image_.type() != CV_8UC3)
				do_reset = true;
		}
		break;
		case XI_RGB32       :
		{
			if (cv_mat_image_.type() != CV_8UC4)
				do_reset = true;
		}
		break;
		case XI_RGB48		:
		{
			if (cv_mat_image_.type() != CV_16UC3)
				do_reset = true;
		}
		break;
		case XI_RGB64		:
		{
			if (cv_mat_image_.type() != CV_16UC4)
				do_reset = true;
		}
		break;
		case XI_RAW32FLOAT	:
		{
			if (cv_mat_image_.type() != CV_32FC1)
				do_reset = true;
		}
		break;
		default:
			ReportException(XI_NOT_SUPPORTED_DATA_FORMAT, "xiAPIplusCameraOcv::resetCvImage");
			return;
	}


	if(do_reset)
	{		
		if (!cv_mat_image_.empty()) cv_mat_image_.release();
		cv_mat_image_ = NULL;

		switch( next_image_->GetDataFormat())
		{
			case XI_MONO8		: cv_mat_image_.create(next_image_->GetHeight(), next_image_->GetWidth() + next_image_->GetPadding_X(), CV_8UC1); printf("Doing reset to mono\n"); break;
			case XI_RAW8		: cv_mat_image_.create(next_image_->GetHeight(), next_image_->GetWidth(), CV_8UC1); printf("Doing reset to RAW\n"); break;
			case XI_RAW8X2		: cv_mat_image_.create(next_image_->GetHeight(), (next_image_->GetWidth()) * 2, CV_8UC1); printf("Doing reset to RAW\n"); break;
			case XI_RAW8X4		: cv_mat_image_.create(next_image_->GetHeight(), (next_image_->GetWidth()) * 4, CV_8UC1); printf("Doing reset to RAW\n"); break;
			case XI_MONO16		:
			case XI_RAW16		: cv_mat_image_.create(next_image_->GetHeight(), next_image_->GetWidth(), CV_16UC1); printf("Doing reset to mono/RAW\n"); break;
			case XI_RAW16X2		: cv_mat_image_.create(next_image_->GetHeight(), (next_image_->GetWidth()) * 2, CV_16UC1); printf("Doing reset to RAW\n"); break;
			case XI_RAW16X4		: cv_mat_image_.create(next_image_->GetHeight(), (next_image_->GetWidth()) * 4, CV_16UC1); printf("Doing reset to RAW\n"); break;
			case XI_RAW32FLOAT	: cv_mat_image_.create(next_image_->GetHeight(), next_image_->GetWidth(), CV_32FC1); printf("Doing reset to RAW\n"); break;
			case XI_RGB24		: cv_mat_image_.create(next_image_->GetHeight(), next_image_->GetWidth(), CV_8UC3);	printf("Doing reset to RGB\n"); break;
			case XI_RGB_PLANAR	: cv_mat_image_.create(next_image_->GetHeight() * 3, next_image_->GetWidth(), CV_8UC1);	printf("Doing reset to RGB PLANAR\n"); break;
			case XI_RGB32		: cv_mat_image_.create(next_image_->GetHeight(), next_image_->GetWidth(), CV_8UC4);	printf("Doing reset to RGB\n"); break;
			case XI_RGB48		: cv_mat_image_.create(next_image_->GetHeight(), next_image_->GetWidth(), CV_16UC3);	printf("Doing reset to RGB\n"); break;
			case XI_RGB16_PLANAR: cv_mat_image_.create(next_image_->GetHeight() * 3, next_image_->GetWidth(), CV_16UC1);	printf("Doing reset to RGB PLANAR\n"); break;
			case XI_RGB64		: cv_mat_image_.create(next_image_->GetHeight(), next_image_->GetWidth(), CV_16UC4);	printf("Doing reset to RGB\n"); break;
			default :
				ReportException(XI_NOT_SUPPORTED_DATA_FORMAT, "xiAPIplusCameraOcv::resetCvImage");
				return;
		}
	}
	return;
}