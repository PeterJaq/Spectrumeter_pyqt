import Spectrumeter_pyQt.utils.camPy as camPy
import time

Cam = camPy.Spect_cam_api()

time.sleep(10)

Cam.close_cam()