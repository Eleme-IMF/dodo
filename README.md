React Native Location Module
============================

## 1. Introduction

Eleme location (based on amap) react native module.

Native module based on:

- AMap Android sdk version: 3.1.0 .

- AMap iOS sdk version:

 -  AMapFoundationKit 1.3.3
 -  AMapLocationKit 2.2.0


## 2. Usage

### 2.1 Installation

#### Step 1

run ```npm install ele-react-native-location --save```

### 2.2 Android Configuration

- android/setting.gradle

```
include ':ele-react-native-location'
project(':ele-react-native-location').projectDir = new File(rootProject.projectDir, '../node_modules/ele-react-native-location/android')
```
- android/app/build.gradle

```
compile project(":ele-react-native-location")
```

- MainApplication.java

```
	@Override
    protected List<ReactPackage> getPackages() {
      return Arrays.<ReactPackage>asList(
          ...,
          new AMapLocationReactPackage() // Add this line
      );
    }
```

- AndroidManifest.xml

```
 <!--用于进行网络定位-->
    <uses-permission android:name="android.permission.ACCESS_COARSE_LOCATION"></uses-permission>
    <!--用于访问GPS定位-->
    <uses-permission android:name="android.permission.ACCESS_FINE_LOCATION"></uses-permission>
    <!--获取运营商信息，用于支持提供运营商信息相关的接口-->
    <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE"></uses-permission>
    <!--用于访问wifi网络信息，wifi信息会用于进行网络定位-->
    <uses-permission android:name="android.permission.ACCESS_WIFI_STATE"></uses-permission>
    <!--这个权限用于获取wifi的获取权限，wifi信息会用来进行网络定位-->
    <uses-permission android:name="android.permission.CHANGE_WIFI_STATE"></uses-permission>
    <!--用于访问网络，网络定位需要上网-->
    <uses-permission android:name="android.permission.INTERNET"></uses-permission>
    <!--用于读取手机当前的状态-->
    <uses-permission android:name="android.permission.READ_PHONE_STATE"></uses-permission>
    <!--写入扩展存储，向扩展卡写入数据，用于写入缓存定位数据-->
    <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE"></uses-permission>
    <uses-permission android:name="android.permission.INTERNET" />
```

Remember setting your custom amap key as follows!

```
 <!--高德地图SDK key设置-->
    <meta-data
        android:name="com.amap.api.v2.apikey"
        android:value="请填写您的key"/>
    <!--高德地图APS服务设置-->
    <service android:name="com.amap.api.location.APSService" ></service>
```

### 2.3 iOS Configuration

- Drag ./node_modules/ele-react-native-location/ios/ELMRNLocation.xcodeproj to your Main Project as a Library

- Add AMap SDK to your project. AMap official tutorial is [here](http://lbs.amap.com/api/ios-location-sdk/guide/crest-project/manual-configuration/)

- AppDelegate.m

```
...
#import <AMapFoundationKit/AMapFoundationKit.h> //引入高德地图核心包
...
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{

  [AMapServices sharedServices].apiKey = @"请填写您的key";
    ...
}
...
```

## 3. API

```
import EleRNLocation from 'ele-react-native-location';
```

### 3.1 Start Location

```
EleRNLocation.startLocation(options);
```

The parameter for startLocation(options) can be varied on different platforms which is showed as following:

#### Android Options and Default Value

```
{
  accuracy: 'HighAccuracy', // BatterySaving(低功耗定位模式), DeviceSensors(仅设备定位模式), HighAccuracy(高精度模式)
  needAddress: true, // 设置是否返回地址信息
  onceLocation: false, // 是否只定位一次
  onceLocationLatest: false,//获取最近3s内精度最高的一次定位结果
  wifiActiveScan: true, // 设置是否强制刷新WIFI，默认为强制刷新,模式为仅设备模式(Device_Sensors)时无效
  mockEnable: false, // 设置是否允许模拟位置,默认为false，不允许模拟位置,模式为低功耗模式(Battery_Saving)时无效
  interval: 2000, // 设置定位间隔,单位毫秒,默认为2000ms
  httpTimeOut: 30000, // 设置联网超时时间(ms), 模式为仅设备模式(Device_Sensors)时无效,默认30000毫秒，建议超时时间不要低于8000毫秒,
  protocol:'http', //用于设定网络定位时所采用的协议，提供http/https两种协议,默认值http
  locationCacheEnable: false //true表示使用定位缓存策略；false表示不使用。默认是false
}
```

#### iOS Options and Default Value

```
{
  accuracy: 'kCLLocationAccuracyHundredMeters', // kCLLocationAccuracyHundredMeters, kCLLocationAccuracyBest, kCLLocationAccuracyNearestTenMeters,kCLLocationAccuracyKilometer,kCLLocationAccuracyThreeKilometers
  onceLocation: false, // 是否只定位一次,
  pausesLocationUpdatesAutomatically: true,//指定定位是否会被系统自动暂停。默认为YES
  allowsBackgroundLocationUpdates: false,//是否允许后台定位。默认为NO。只在iOS 9.0及之后起作用。设置为YES的时候必须保证 Background Modes 中的 Location updates 处于选中状态，否则会抛出异常
  locationTimeout: 10,//指定单次定位超时时间,默认为10s。最小值是2s。注意单次定位请求前设置
  reGeocodeTimeout: 5,//指定单次定位逆地理超时时间,默认为5s。最小值是2s。注意单次定位请求前设置
  locatingWithReGeocode: false,//连续定位是否返回逆地理信息，默认NO
  distanceFilter: 'kCLDistanceFilterNone'//设定定位的最小更新距离。默认为 kCLDistanceFilterNone 
}
```


More config options detail can he found [here](http://lbs.amap.com/api/android-location-sdk/guide/android-location/getlocation/#configure)

### 3.2 Stop Location

```
EleRNLocation.stopLocation();
```

### 3.3 Destroy Location

```
EleRNLocation.destroyLocation();
```

### 3.4 Add Location Update Listener

```
EleRNLocation.addEventListener((data) => console.log('data', data));
```

#### Result Received from Event Listener

```
{
    "gpsStatus": -1, (Android only)
    "locationDetail": "", (Android only)
    "district": "", 
    "city": "", 
    "street": "", 
    "aoiName": "", 
    "poiName": "", 
    "province": "", 
    "locationType": 1, (Android only)
    "latitude": 36.669221634428474, 
    "altitude": 29.78, 
    "cityCode": "", 
    "streetNum": "", 
    "bearing": 0, (Android only)
    "accuracy": 1, (Android only)
    "horizontalAccuracy": 1, (iOS only)
    "verticalAccuracy": 1, (iOS only)
    "speed": 0, (Android only)
    "longitude": 117.0259247042361, 
    "adCode": "", 
    "country": "", 
    "address": ""
}
```

Result detail can be found [here](http://lbs.amap.com/api/android-location-sdk/guide/android-location/getlocation/#result)

*tips*: The k-v in the result maybe contains "", 0 since certain values are exclusive which are varied with different options.

#### Handling Errors

Location update listener will receiver error when there is something unexpected happened.

```
{
	errorCode: 2,
	errorInfo: 'WIFI信息不足 请到http://lbs.amap.com/api/android-location-sdk/abouterrorcode/查看错误码说明.'
}
```

Amap provide a full [table](http://lbs.amap.com/api/android-location-sdk/guide/utilities/errorcode/)  of error code and it's detail info.

## 4. Example

```
/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 * @flow
 */

import React, { Component } from 'react';
import {
  AppRegistry,
  StyleSheet,
  Text,
  View
} from 'react-native';

import EleRNLocation from 'ele-react-native-location';


export default class LocationExample extends Component {
  render() {
    return (
      <View style={styles.container}>
        <Text style={styles.welcome}>
          Welcome to React Native!
        </Text>
        <Text style={styles.instructions}>
          To get started, edit index.android.js
        </Text>
        <Text style={styles.instructions}>
          Double tap R on your keyboard to reload,{'\n'}
          Shake or press menu button for dev menu
        </Text>
      </View>
    );
  }

  componentDidMount() {
    this.listener = EleRNLocation.addEventListener((data) => console.log('data', data));
    // for Android (iOS options is different)
    EleRNLocation.startLocation({
      accuracy: 'HighAccuracy',
      mockEnable: true,
      interval: 5000
    });
  }

  componentWillUnmount() {
    EleRNLocation.stopLocation();
    this.listener.remove();
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#F5FCFF',
  },
  welcome: {
    fontSize: 20,
    textAlign: 'center',
    margin: 10,
  },
  instructions: {
    textAlign: 'center',
    color: '#333333',
    marginBottom: 5,
  },
});

AppRegistry.registerComponent('LocationExample', () => LocationExample);
```

## 5. Release Note
- [*] 0.2.2
  - 升级高德SDK iOS 基础framework 到 V1.3.4
  - 升级高德SDK iOS 定位framework 到 V2.3.0
  - Fix [bug](https://github.com/Eleme-IMF/dodo/issues/11)
- [*] 0.2.1
  - 升级高德SDK jar包到 V3.3 
  - Fix [bug](https://github.com/Eleme-IMF/dodo/issues/9)
- [*] 0.2.0
  - 兼容 RN 0.40 


## 5. Any Help

Issues and PR are welcomed!

Support wantted? Please contact:

- Android: [hongju.wang](hongju.wang@ele.me)

- iOS: [liangliang.gao](liangliang.gao@ele.me)
