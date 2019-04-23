// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SlackNotifySettings.generated.h"

/**
 * 
 */
UCLASS(config =SlackNotify, defaultconfig)
class SLACKNOTIFYPLUGIN_API USlackNotifySettings : public UObject
{
	GENERATED_BODY()
public:
	USlackNotifySettings(const FObjectInitializer& ObjectInitializer);

	/** 送信先チャンネルID */
	UPROPERTY(config, EditAnywhere, Category = "Settings")
	bool bEnableLightBuildNotify = true;
	
	/** 送信先チャンネルURL */
	UPROPERTY(config, EditAnywhere, Category = "Settings", meta = (EditCondition = "bEnable"))
	FString WebhookUrl;

	/** 送信先チャンネルID */
	UPROPERTY(config, EditAnywhere, Category ="Settings", meta = (EditCondition = "bEnable"))
	FString ChannelID;
	
	/** 送信者の名前 */
	UPROPERTY(config, EditAnywhere, Category = "Settings", meta = (EditCondition = "bEnable"))
	FString Username;

	/** 送信者のアイコン */
	UPROPERTY(config, EditAnywhere, Category = "Settings", meta = (EditCondition = "bEnable"))
	FString IconEmoji;

	static USlackNotifySettings* Get()
	{
		return Cast<USlackNotifySettings>(USlackNotifySettings::StaticClass()->GetDefaultObject());
	}
};
