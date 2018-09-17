import ctypes

class Spect_cam_api:

    def __init__(self, *args, **kwargs):
        lib_loader = ctypes.cdll.LoadLibrary
        self.cam_api = lib_loader("../libs/400A/include/CamApi.h")
        self.init_cam()

        
        
    def init_cam():

        self.cam_api.InitDevice("")
        total = self.cam_api.DeviceCount()
        if(total is True):
            print("Spectrumeter connect is Success!" )
            return True
        else:
            print("WARNING!: Spectrumeter connect is not success!")
            return False

    def get_cam_info():
        
        self.DeviceProduct = self.cam_api.DeviceProduct

        return True
