import Spectrumeter_pyQt.utils.camPy as camPy
import time
import numpy

Cam = camPy.Spect_cam_api()
print(Cam.Set_Resolution())
depth_debug = Cam.get_depth()
print(Cam.get_raw_size())
raw_data, img_data = Cam.get_raw_data()
print(Cam.get_res_size())
H, W = Cam.get_raw_size()
img = numpy.array(img_data)
raw = numpy.array(raw_data)
numpy.savetxt("./result_raw.txt", img, fmt='%s')
numpy.savetxt("./result_img.txt", raw, fmt='%s')
print(img, raw)
time.sleep(10)
Cam.close_cam()