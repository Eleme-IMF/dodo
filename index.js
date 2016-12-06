import {NativeModules, DeviceEventEmitter} from 'react-native';

const EleRNLocation = NativeModules.EleRNLocation;
const onLocationChanged = 'onLocationChangedEvent';


export default class Location {

  static startLocation(options) {
    EleRNLocation.startLocation(options);
  }

  static stopLocation() {
    EleRNLocation.stopLocation();
  }

  static destroyLocation() {
    EleRNLocation.destroyLocation();
  }

  static addEventListener(handler) {

    const listener = DeviceEventEmitter.addListener(
        onLocationChanged,
        handler,
    );
    return listener;
  }
}
