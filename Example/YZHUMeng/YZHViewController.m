//
//  YZHViewController.m
//  YZHUMeng
//
//  Created by yinzhihao on 03/23/2023.
//  Copyright (c) 2023 yinzhihao. All rights reserved.
//

#import "YZHViewController.h"
#import <YZHUMeng/YZHUMeng.h>

//http://172.18.80.126:8090/pages/viewpage.action?pageId=72059325

@interface YZHViewController ()

@end

@implementation YZHViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}
- (IBAction)start:(id)sender {
    [YZHUMengManager.shared event:@"Event_test" attributes:@{
        @"key1":@"value1",
        @"key2":@"value2"
    }];
    [YZHUMengManager.shared beginEvent:@"Event_test1"];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [YZHUMengManager.shared endEvent:@"Event_test1"];
    });
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
