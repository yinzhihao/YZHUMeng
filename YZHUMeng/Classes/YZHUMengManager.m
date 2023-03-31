//
//  YZHUMengManager.m
//  YZHUMeng
//
//  Created by NO NAME on 2023/3/23.
//

#import "YZHUMengManager.h"
#import <UMCommon/UMCommon.h>
#import <UMCommonLog/UMCommonLogHeaders.h>

@implementation YZHUMengManager

+ (instancetype)shared {
    static YZHUMengManager *_shared = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _shared = [[YZHUMengManager alloc] init];
    });
    return _shared;
}

- (void)configUMengWithAppKey:(NSString *)appKey channel:(NSString *)channel logEnabled:(BOOL)logEnabled {
    
    /* 打开调试日志 */
    [UMConfigure setLogEnabled:logEnabled];
    //初始化
    [UMConfigure initWithAppkey:appKey channel:channel];
    //开发者需要显式的调用此函数，日志系统才能工作
    [UMCommonLogManager setUpUMCommonLogManager];
}

@end
