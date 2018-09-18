import ctypes
import string
import time

class Spect_cam_api:

    def __init__(self, mExposure = ctypes.c_int(10)):
        lib_loader = ctypes.cdll.LoadLibrary
        self.cam_api = lib_loader("../libs/400A/lib/Camkernel.dll")
        self.mExposure = mExposure
        self.dev_name = None
        self.camSolutionH = 2048
        self.camSoluationW = 2048
        self.init_cam()

    def init_cam(self):

        self.cam_api.InitDevice("")
        total = self.cam_api.DeviceCount()

        if total is 1:
            print("Spectrumeter connect is Success!" )
        else:
            print("WARNING!: Spectrumeter connect is not success!")

        self.cam_api.ExitDevice()
        self.cam_api.InitDevice()
        self.dev_name = self.cam_api.DeviceName(0)
        self.cam_api.ResetDevice(self.dev_name)
        self.cam_api.SetExposure(self.mExposure, self.dev_name)
        self.cam_api.SetCooled(ctypes.c_bool(self.get_cam_temp().value >= -20), self.dev_name)

        return True

    def close_cam(self):
        self.cam_api.SuspendDevice(self.dev_name)

        return True

    def get_cam_temp(self):
        temperature = ctypes.c_float()

        self.cam_api.GetTemperature(ctypes.byref(temperature), self.dev_name)

        return temperature

    def get_raw_data(self):

        size = self.cam_api.RecvMemSize(self.dev_name)
        bufferRaw = (ctypes.c_ubyte * size)()
        bufferImg = (ctypes.c_ubyte * size)()
        self.cam_api.GetRawData(bufferRaw, size, self.dev_name)
        self.cam_api.DecodeRaw2Image(bufferRaw, bufferImg, self.dev_name)

        self.cam_api.GetSharpness(self.dev_name)

        """
        for (int i = 0, j = headSz; i < pixels & & j < size - 1; i++, j += offset)
            {
                ushort
            value = bufferImg[j] + (bufferImg[j + 1] << 8); // Big
            Endian

            if (value > 65000)
            {
                count + +;
            }

            tmpData << value;
            }
        """

        return [x for x in bufferRaw], [x for x in bufferImg]

    def get_res_size(self):

        img_W = self.cam_api.GetResWidth(0, self.dev_name)
        img_H = self.cam_api.GetResHeight(0, self.dev_name)

        return img_W, img_H

    def get_raw_size(self):

        self.H = ctypes.c_int(0)
        self.W = ctypes.c_int(0)
        self.cam_api.GetRawSize(ctypes.byref(self.W), ctypes.byref(self.H), self.dev_name)
        return self.H.value, self.W.value

    def Set_Resolution(self):
        """

        :return: Resolution of this frame
        """
        i = 0
        self.cam_api.SetResolution(i, self.dev_name)
        return "The Resolution of Cam:" + str(self.cam_api.GetResolution(self.dev_name))

    def set_image_format(self, imgType=ctypes.c_int(0)):
        """
        :param imgType: [SNAP_RAW, SNAP_BMP, SNAP_JPG, SNAP_TIF, SNAP_PNG]

                        image formats include RAW, BMP, JPG, TIF, PNG
        """
        print("SET_IMG_FORMAT:%d" % self.cam_api.SetImageFormat(imgType, self.dev_name))


    def get_image(self, path=b"../image\\"):
        """
        API: void SetImageFormat(int picType, const char *devName)
        :param path: image path
        :return:
        """
        self.set_image_format(ctypes.c_int(8))
        size = self.cam_api.RecvMemSize(self.dev_name)
        bufferRaw = (ctypes.c_ubyte * size)()

        print(self.cam_api.SaveFile(bufferRaw, ctypes.c_char_p(path), 8, self.dev_name))

        return [x for x in bufferRaw]

    def get_depth(self):
        print(self.cam_api.GetRawDepth(self.dev_name))
    """
        def set_raw_depth(self, depth=ctypes.c_int(8)):
        print(self.cam_api.SetRawDepth(depth, self.dev_name))
        if self.cam_api.SetRawDepth(depth, self.dev_name) is 0:
            return "set_raw_depth is successful!"
        else:
            return "ERROR : set_raw_depth "
    """
















