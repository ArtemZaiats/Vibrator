#define LOG_TAG "android.hardware.vibrator@1.0-service"

#include <android/hardware/vibrator/1.0/IVibrator.h>
#include <hidl/HidlTransportSupport.h>
#include <Vibrator.h>

using android::hardware::vibrator::V1_0::IVibrator;
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;

using namespace android;
using namespace android::hardware::vibrator::V1_0::implementation;

int main() {
	android::sp<IVibrator> service = new Vibrator();

	configureRpcThreadpool(1, true /* callerWillJoin */);

	// Register our service -- if somebody is already registered by our name,
	// they will be killed (their thread pool will throw an exception).
	status_t status = service->registerAsService();
	if(status == OK) {
		ALOGD("Vibrator is ready.");
		joinRpcThreadpool();
	} else {
		ALOGE("Could not register service (%d).", status);
	}

	// In normal operation, we din't expect the thread pool to exit
	ALOGE("Vibrator is shutting down");
	return 1;
}