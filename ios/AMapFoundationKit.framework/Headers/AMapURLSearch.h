//
//  AMapURLSearch.h
//  AMapFoundation
//
//  Created by xiaoming han on 15/10/28.
//  Copyright © 2015年 AutoNavi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AMapURLSearchConfig.h"

/// 调起高德地图URL进行搜索，若是调起失败，可使用`+ (void)getLatestAMapApp;`方法获取最新版高德地图app.
@interface AMapURLSearch : NSObject

/// 打开高德地图AppStore页面
+ (void)getLatestAMapApp;

/**
 *  调起高德地图app驾车导航.
 *
 *  @param config 配置参数.
 *
 *  @return 是否成功.若为YES则成功调起，若为NO则无法调起.
 */
+ (BOOL)openAMapNavigation:(AMapNaviConfig *)config;

/**
 *  调起高德地图app进行路径规划.
 *
 *  @param config 配置参数.
 *
 *  @return 是否成功.
 */
+ (BOOL)openAMapRouteSearch:(AMapRouteConfig *)config;

/**
 *  调起高德地图app进行POI搜索.
 *
 *  @param config 配置参数.
 *
 *  @return 是否成功.
 */
+ (BOOL)openAMapPOISearch:(AMapPOIConfig *)config;

@end
