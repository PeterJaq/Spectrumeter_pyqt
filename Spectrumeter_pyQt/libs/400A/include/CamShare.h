///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
// AUTHOR:        jorgo(wuhua@tsdt.net) 
//				  Ezio(jorgo@163.com) on 12-5-11
// COPYRIGHT:     Tucsen Imaging Technology Co.,ltd
//                (www.tsdt.net). All rights reserved.
////////////////////////////////////////////////////////////////////////////////
#ifndef __CAM_SHARE_H
#define __CAM_SHARE_H

#define EOS_WINDOWS   1
//#define OS_DARWIN    1
//#define OS_LINUX     1
//#define OS_ANDROID   1

#define LMOVE(i) (1<<(i))

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

// version
enum {
	VERSION_TIME   = 0x001,
	VERSION_NUMBER,
	VERSION_VENDOR,
};

// device states 
enum {
	DEV_CONNECTION,
	DEV_ACTIVATION,	
	DEV_EXECUTION,
	DEV_DISCONNECTION,
};
	
//return code	
enum {
	NO_MEMORY		=-7,
	NO_PERMISSION   =-6,
	NO_DEFECTCORECT =-5,
	NO_SUPPORT		=-4,
	NO_SUCCEED		=-3,
	NO_RANGE		=-2,
	NO_CAMERA       =-1,
	NO_FAIL         = 0,
	ACTIVE_EXTERNAL = 1,
	FLUORESCENCE    = 2,
	FLUORESCENCE2	= 3,
	NOW_NONSUPPORT	= 4,
	DEFECTCORECT    = 5,
};			

// Image type
enum {
	SNAP_RAW = 0x01,
	SNAP_TIF = 0x02,
	SNAP_PNG = 0x04,
	SNAP_JPG = 0x08,
	SNAP_BMP = 0x10,
};

// Mirror
enum {
	FLIP_HORIZONTAL = 0x01,
	FLIP_VERTICAL,
	FLIP_BOTH,
};

// Rotate
enum {
	ROTATE_LEFT_90	= 0x01,
	ROTATE_RIGHT_90,
	ROTATE_BOTH,
};

// The Head position of image
enum {
	RAW_OFT_WIDTH      = sizeof(char)<<2,
	RAW_OFT_HEIGHT     = sizeof(ushort)+RAW_OFT_WIDTH,
	RAW_OFT_DEPTH      = sizeof(ushort)+RAW_OFT_HEIGHT,
	RAW_OFT_CHANNELS   = sizeof(char)  +RAW_OFT_DEPTH,
	RAW_OFT_BAYER      = sizeof(char)  +RAW_OFT_CHANNELS,
	RAW_OFT_RESOLUTION = sizeof(char)  +RAW_OFT_BAYER,
	RAW_OFT_HEAD       = sizeof(char)  +RAW_OFT_RESOLUTION,
	RAW_OFT_HISTO      = sizeof(ushort)*2+RAW_OFT_HEAD+sizeof(uchar *),
	RAW_OFT_MEAN_B     = sizeof(char)  +RAW_OFT_HISTO,
	RAW_OFT_MEAN_G     = sizeof(char)  +RAW_OFT_MEAN_B,
	RAW_OFT_MEAN_R     = sizeof(char)  +RAW_OFT_MEAN_G,
};

// BAYER TYPE 
enum {
	BAYER_BW, 
	BAYER_RG,
	BAYER_GR,
	BAYER_BG,
	BAYER_GB,
	FMT_YUY2,
};

// The order of 16bit RAW data.
enum {
	RMAC_C0AB = 0x00,
	RMAC_0CAB = 0x01,
	RMAC_ABC0 = 0x02,
	RMAC_AB0C = 0x03,
};

// smooth method
enum {
	EZSM_MIDDLE   = 0x0001,
	EZSM_GAUSSIAN = 0x0002,
};

// GPIO
enum {
	GPIO11 = 1,
	GPIO22,
	GPIO33,
};

typedef struct __IMG_RECT
{
    int left;
    int top;
    int right;
    int bottom;
} IMGRT, *PIMGRT;

typedef void *(*PCB)(unsigned char *pBuffer);

#endif
