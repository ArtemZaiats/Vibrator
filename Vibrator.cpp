
#define LOG_TAG "VibratorService"

#include <inttypes.h>

#include <log/log.h>

#include "Vibrator.h"

namespace android {
namespace hardware {
namespace vibrator {
namespace V1_0 {
namespace implementation {

// Methods from ::android::hardware::vibrator::V1_0::IVibrator follow.
Return<Status> Vibrator::on(uint32_t timeout_ms) {
    ALOGI("Vibrator::on %u", timeout_ms);
    return Status::OK;
}

Return<Status> Vibrator::off()  {
    ALOGI("Vibrator::off");
    return Status::OK;
}

Return<bool> Vibrator::supportsAmplitudeControl()  {
    ALOGI("Vibrator::supportsAmplitudeControl");
    return false;
}

Return<Status> Vibrator::setAmplitude(uint8_t) {
    ALOGI("Vibrator::setAmplitude");
    return Status::UNSUPPORTED_OPERATION;
}

Return<void> Vibrator::perform(Effect, EffectStrength, perform_cb _hidl_cb) {
    ALOGI("Vibrator::perform");
    _hidl_cb(Status::UNSUPPORTED_OPERATION, 0);
    return Void();
}


} // namespace implementation
}  // namespace V1_0
}  // namespace vibrator
}  // namespace hardware
}  // namespace android
