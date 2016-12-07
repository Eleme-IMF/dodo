'use strict';

var ReactNative = require('react-native');

var {
    NativeModules,
    DeviceEventEmitter
} = ReactNative;

const EleRNLocation = NativeModules.EleRNLocation;
const onLocationChanged = 'onLocationChangedEvent';

module.exports = {
    startLocation: function (options) {
        EleRNLocation.startLocation(options);
    },
    stopLocation: function () {
        EleRNLocation.stopLocation();
    },
    destroyLocation: function () {
        EleRNLocation.destroyLocation();
    },
    addEventListener: function (handler) {
        const listener = DeviceEventEmitter.addListener(
            onLocationChanged,
            handler
        );
        return listener;
    }
};
