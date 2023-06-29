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
- (void)configUMengWithAppKey:(NSString *)appKey channel:(nullable NSString *)channel logEnabled:(BOOL)logEnabled;

/** 自定义事件,数量统计.
使用前，请先到友盟App管理后台的设置->编辑自定义事件 中添加相应的事件ID，然后在工程中传入相应的事件ID
 
 @param  eventId 网站上注册的事件Id.
 @param  label 分类标签。不同的标签会分别进行统计，方便同一事件的不同标签的对比,为nil或空字符串时后台会生成和eventId同名的标签.
 */
- (void)event:(NSString *)eventId label:(NSString * _Nullable)label;

- (void)event:(NSString *)eventId attributes:(NSDictionary * _Nullable)attributes;

- (void)event:(NSString *)eventId;

/** 自定义事件,时长统计.
    使用前，请先到友盟App管理后台的设置->编辑自定义事件 中添加相应的事件ID，然后在工程中传入相应的事件ID.
    beginEvent,endEvent要配对使用,也可以自己计时后通过durations参数传递进来
 
 @param  eventId 网站上注册的事件Id.
 
 @warning 每个event的attributes不能超过100个
    eventId、attributes中key和value都不能使用空格和特殊字符，必须是NSString,且长度不能超过255个字符（否则将截取前255个字符）
    id， ts， du是保留字段，不能作为eventId及key的名称
*/
- (void)beginEvent:(NSString *)eventId;

- (void)endEvent:(NSString *)eventId;

- (void)event:(NSString *)eventId durations:(int)millisecond;

@end

NS_ASSUME_NONNULL_END
