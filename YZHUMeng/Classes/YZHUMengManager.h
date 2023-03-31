//
//  YZHUMengManager.h
//  YZHUMeng
//
//  Created by NO NAME on 2023/3/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YZHUMengManager : NSObject

+ (instancetype)shared;

/**
 * 初始化友盟
 */
- (void)configUMengWithAppKey:(NSString *)appKey channel:(NSString *)channel logEnabled:(BOOL)logEnabled;

- (void)reportException:(NSException *)exception;

- (void)reportError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
