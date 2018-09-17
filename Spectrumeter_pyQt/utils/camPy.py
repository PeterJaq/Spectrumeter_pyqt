import ctypes
import string
import time

class Spect_cam_api:

    def __init__(self, mExposure = ctypes.c_int(10)):
        lib_loader = ctypes.cdll.LoadLibrary
        self.cam_api = lib_loader("../libs/400A/lib/Camkernel.dll")
        self.mExposure = mExposure
        self.dev_name = None
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

    def set_image_format(self, imgType=ctypes.c_int(0)):
        """
        :param imgType: [SNAP_RAW, SNAP_BMP, SNAP_JPG, SNAP_TIF, SNAP_PNG]

                        image formats include RAW, BMP, JPG, TIF, PNG

        """

        return self.cam_api.SetImageFormat(imgType, self.dev_name)

    def get_image(self, path="../image/"):
        """
        API: void SetImageFormat(int picType, const char *devName)
        :param path: image path
        :return:
        """

        return self.cam_api.SaveImage(path, 0, self.dev_name)





