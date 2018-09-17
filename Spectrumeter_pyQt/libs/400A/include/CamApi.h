///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
// AUTHOR:        jorgo(wuhua@tsdt.net) 
//				  Ezio(jorgo@163.com) on 12-5-11
// COPYRIGHT:     Tucsen Imaging Technology Co.,ltd
//                (www.tsdt.net). All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#ifndef __CAMAPI_H
#define __CAMAPI_H
#include "CamShare.h"

#if defined (OS_DARWIN)
	#define CAM_API
    CAM_API int InitDevice(void *pnp, void *instance, const char *pathInstance);

#elif defined (EOS_WINDOWS)
    #ifdef CamKernel_EXPORTS
    #define CAM_API extern "C" __declspec(dllexport)
    #else
    #define CAM_API extern "C" __declspec(dllimport)
    #endif
//     CAM_API const char *DeviceGUID();
//     CAM_API const char *DeviceChange(const char *strGuid, bool addDev);
    CAM_API int  InitDevice(const char *pathInstance);

#elif defined (OS_LINUX)
    #if defined(CAMCORE_LIBRARY)
    #define CAM_API __attribute__((visibility("default")))
    #else
    #define CAM_API
    #endif
    extern "C" {
    CAM_API int  InitDevice(const char *pathInstance);
    
#elif defined (OS_ANDROID)
#endif

CAM_API const char *VersionInf(int vType); 
// firmware interface:
CAM_API void ExitDevice();

CAM_API int DeviceCount();
CAM_API const char *DeviceName(int index);
CAM_API int RecvMemSize(const char *devName);
CAM_API int DataHeadLen(const char *devName);
CAM_API int DeviceState(const char *devName);
CAM_API int DeviceProduct(const char *devName);
CAM_API int DeviceVendor(const char *devName);
CAM_API int DeviceBcd(const char *devName);
CAM_API int USBBcd(const char *devName);
CAM_API int DeviceVersion(const char *devName);

CAM_API int ResumeDevice(const char *devName);
CAM_API int SuspendDevice(const char *devName);
CAM_API int ResetDevice(const char *devName);
CAM_API int ResetSupport(const char *devName);

CAM_API int SetResolution(int index, const char *devName);
CAM_API int GetResolution(const char *devName);
CAM_API int GetResolutionCount(const char *devName);
CAM_API const char *GetResItemName(int index, const char *devName);

CAM_API int SetPixelclock(int index, const char *devName);
CAM_API int GetPixelclock(const char *devName);
CAM_API int GetPixelclockCount (const char *devName);
CAM_API const char *GetPixclkItemName(int index, const char *devName);

CAM_API int GetRawSize(int *pWid, int *pHei, const char *devName);
CAM_API int GetResWidth(int indexResolution, const char *devName);
CAM_API int GetResHeight(int indexResolution,const char *devName);

CAM_API int GetRawBayernPattern(const char *devName);
CAM_API int GetRawDepthState(int pixelclockIndex, const char *devName);
CAM_API int GetRawDepth(const char *devName);
CAM_API int SetRawDepth(int dep, const char *devName);

CAM_API int GetRawData(uchar *pBuffer, int len, const char *devName);
CAM_API int DecodeRaw2Image(uchar *pRaw, uchar *pImg, const char *devName);
CAM_API int GetImageChannles(const char *devName);
CAM_API int GetRawDataEx(PCB pAsynCB, uchar *pBufferCB, int len, const char *devName); // v2.0
CAM_API int SetSharpness(int lnVal, const char *devName);// v2.0
CAM_API int GetSharpness(const char *devName);// v2.0
CAM_API int GetSharpnessRange(int *pMinVal, int *pMaxVal, int *pStepVal, const char *devName);// v2.0
CAM_API int SetDenoise(int lnVal, const char *devName);// v2.0
CAM_API int GetDenoise(const char *devName);// v2.0
CAM_API int GetDenoiseRange(int *pMinVal, int *pMaxVal, int *pStepVal, const char *devName);// v2.0

CAM_API int SetHDR(bool bHDR, const char *devName);
CAM_API int GetHDR(bool *pHDR, const char *devName);

CAM_API int ResetFrameCount(const char *devName);
CAM_API int SetDataMode(bool bFrame, const char *devName);
CAM_API int GetDataMode(bool *pbFrame, const char *devName);

CAM_API int SetTriggerPolarity(bool bFrame, const char *devName);
CAM_API int GetTriggerPolarity(bool *pbFrame, const char *devName);
CAM_API int SetTriggerDelay(int dltime, const char *devName);

CAM_API int GetAnaloggainRange(int *pMinVal, int *pMaxVal, int *pStepVal, const char *devName);
CAM_API int GetAnaloggain(const char *devName);
CAM_API int SetAnaloggain(int gain, const char *devName);

CAM_API int GetExposureRange(float *pMinVal, float *pMaxVal, float *pStepVal, const char *devName);
CAM_API float GetExposure(const char *devName);
CAM_API int SetExposure(float v, const char *devName);

CAM_API int SetBlacklevel(int lnVal, const char *devName);
CAM_API int GetBlacklevel(const char *devName);
CAM_API int GetBlacklevelRange(int *pMinVal, int *pMaxVal, int *pStepVal, const char *devName);
CAM_API int SetRoi(int pointx, int pointy, int wid, int hei, const char *devName);
CAM_API int GetRoi(int *pPtX, int *pPtY, int *wid, int *hei, const char *devName);
CAM_API int SetRoiState(bool state, const char *devName);
CAM_API int GetRoiState(bool *pState, const char *devName); 
CAM_API int WriteInf(char *pWrite, int size, const char *devName);
CAM_API int ReadInf(char *pRead,  int size, const char *devName);
CAM_API int SetEdgeInhibition(bool state, const char *devName);	
CAM_API int GetEdgeInhibition(bool *pS, const char *devName);
CAM_API int SetGpio(int index, bool state, const char *devName);	// index: GPIO11~GPIO33
CAM_API int Gpio(int index, bool *pS, const char *devName);
CAM_API int SetCooled(bool state, const char * devName);
CAM_API int GetCooled(bool *pS, const char * devName);
CAM_API int GetTemperature(float *fTemperature, const char *devName);

// algorithms interface:
// camera algorithms
CAM_API void SetContrast(int contrast, const char *devName);
CAM_API int GetContrast(const char *devName);
CAM_API int GetContrastRange(int *pMinVal, int *pMaxVal, int *pStepVal, const char *devName);
CAM_API void SetFlip(int flip, const char *devName);
CAM_API int GetFlip(const char *devName);
CAM_API void SetRotate(int rotate, const char *devName);
CAM_API int GetRotate(const char *devName);    
        
CAM_API void SetAutoExposure(bool bAE, const char *devName);
CAM_API int GetAutoExposure(bool *pAE, const char *devName);
CAM_API void SetAETarget(int aeVal, const char *devName);
CAM_API int GetAETarget(const char *devName);
CAM_API int GetAETargetRange(int *pMinVal, int *pMaxVal, int *pStepVal, const char *devName);

CAM_API int GetFlatfieldState(bool *check, const char *devName);
CAM_API void SetFlatfieldState(bool check, const char *devName);
CAM_API int CalcFlatfield(uchar *pRawData, bool autoFF, const char *devName);
CAM_API int SetDefectCorrectionState(bool check, const char *devName);
CAM_API int GetDefectCorrectionState(bool *pChk, const char *devName);
CAM_API void CalcDefectCorrection(const char *devName);

// color params
CAM_API void SetColorEnhancement(bool bColor, const char *devName);
CAM_API int GetColorEnhancement(bool *pColor, const char *devName);
CAM_API void SetSaturation(int saturation, const char *devName);
CAM_API int GetSaturation(const char *devName);
CAM_API int GetSaturationRange(int *pMinVal, int *pMaxVal, int *pStepVal, const char *devName);
CAM_API void SetMonochrome(bool mono, const char *devName);
CAM_API int GetMonochrome(bool *pMono, const char *devName);
CAM_API int CalcWhiteBalance(uchar *pRawData, PIMGRT pRT, const char * devName); //V2.0
CAM_API int GetWhiteBalanceState(bool *pBW, const char * devName);

CAM_API void SetImageFormat(int picType, const char *devName);
CAM_API int GetImageFormat(int *picType, const char *devName);
CAM_API int SaveImage(const char *path, int picRes, const char *devName);
CAM_API int SaveImageEx(const char *path, int picRes, PCB pfn, const char *devName);
CAM_API int SaveFile(uchar *rawdata, const char *path, int saveType, const char *devName);

CAM_API int SetDefaultConfiguration(const char *devName);
CAM_API int GetCurrentConfiguration(const char *devName); 
CAM_API int SaveConfiguration(int index, const char *devName);
CAM_API int LoadConfiguration(int index, const char *devName);

// independence algorithms
CAM_API int ResizeImage(uchar *pSrc, uchar *pDst, int dstWidth, int dstHeight);
CAM_API int CalcAverage(uchar *pImage);
CAM_API int ShiftOperation(uchar *pImage, int shift);
CAM_API int SetShiftOperator(int oft, const char *devName); // 1.2
CAM_API int GetShiftOperator(const char *devName); //1.2
CAM_API int GetShiftOperatorRange(int *pMinVal, int *pMaxVal, int *pStepVal, const char *devName); // 1.2

CAM_API int GetPointIntensity(int x,int y, uchar *pImage);
CAM_API int GetImageIntensity(uchar *pRawFrame,  
							  int startX,  
							  int startY,  
							  int width,  
							  int height,  
							  float *pIntensity,  
							  float *pRedIntensity,  
							  float *pGreen1Intensity,  
							  float *pGreen2Intensity,  
							  float *pBlueIntensity);


// invalid interface
CAM_API void SetGamma(int gamma, const char *devName); // 0.9~1.2
CAM_API int GetGamma(const char *devName);// 0.9~1.2
CAM_API int GetGammaRange(int *pMinVal, int *pMaxVal, int *pStepVal, const char *devName);// 0.9~1.2
CAM_API int SetStretch(int uMin, int uMax, bool bAuto, const char *devName); // 0.9~1.2
CAM_API int GetStretch(int *pMinVal, int *pMaxVal, bool *pAuto, const char *devName);// 0.9~1.2
CAM_API int GetStretchRange(int *pMinVal, int *pMaxVal, int *pStepVal, const char *devName);// 0.9~1.2

CAM_API void SetHistogramState(bool bState, const char *devName);// 0.9~1.2
CAM_API int GetHistogramState(bool *pState, const char *devName);// 0.9~1.2

CAM_API void SetChannelGain(int channel0, int channel1, int channel2, const char *devName);	
CAM_API int GetChannelGain(int *pChannel0, int *pChannel1, int *pChannel2, const char *devName);
CAM_API int GetChannelGainRange(int *pMinVal, int *pMaxVal, int *pStepVal, const char *devName);


// v1.2.2
CAM_API void SetGammaEx(int gamma, int channel, const char *devName);// 1.2.2~
CAM_API int GetGammaEx(int channel, const char *devName);// 1.2.2~
CAM_API int GetGammaRangeEx(int *pMinVal, int *pMaxVal, int *pStepVal, int channel, const char *devName);// 1.2.2~
CAM_API int SetStretchEx(int uMin, int uMax, bool bAuto, int channel, const char *devName); // 1.2.2~
CAM_API int GetStretchEx(int *pMinVal, int *pMaxVal, bool *pAuto, int channel, const char *devName);// 1.2.2~
CAM_API int GetStretchRangeEx(int *pMinVal, int *pMaxVal, int *pStepVal, int channel, const char *devName);// 1.2.2~
CAM_API int FluorescenceGuide(int step, int bin, const char *devName);// 1.2.2~

CAM_API void CalcBlackField(const char *devName);
CAM_API int SetBlackFieldState(bool check, const char *devName);
CAM_API int GetBlackFieldState(bool *pCheck, const char *devName);

CAM_API int SetFilter(bool bfilter, const char *devName);
CAM_API int GetFilter(bool *pbfilter, const char *devName);
CAM_API int UpdateFirmware(const char* szfileiic, const char *devName);



#if defined (EOS_WINDOWS)

#elif defined (OS_LINUX)
};
#elif defined (OS_DARWIN)

#elif defined (OS_ANDROID)

#endif

#endif // __CAMAPI_H
