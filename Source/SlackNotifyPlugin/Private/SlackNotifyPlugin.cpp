// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SlackNotifyPlugin.h"
#include "SlackIntegrations/Public/SlackIntegrationsModule.h"
#include "SlackIntegrations/Public/ISlackIncomingWebhookInterface.h"
#include "SlackIntegrations/Public/SlackIntegrations.h"
#include "SlackNotifySettings.h"
#include "ISettingsModule.h"

#define LOCTEXT_NAMESPACE "FSlackNotifyPluginModule"

void FSlackNotifyPluginModule::OnLightBuildSucceeded()
{
	if (!USlackNotifySettings::Get()->bEnableLightBuildNotify)
	{
		return;
	}
	FSlackIncomingWebhook webhook;
	webhook.Channel = USlackNotifySettings::Get()->ChannelID;
	webhook.Username = USlackNotifySettings::Get()->Username;
	webhook.IconEmoji = USlackNotifySettings::Get()->IconEmoji;
	webhook.WebhookUrl = USlackNotifySettings::Get()->WebhookUrl;
	FSlackMessage message;

	message.MessageText = FString("LightBuild Succeeded.");
	ISlackIntegrationsModule::Get().GetIncomingWebhookInterface().SendMessage(webhook, message);
}

void FSlackNotifyPluginModule::OnLightBuildFailed()
{
	if (!USlackNotifySettings::Get()->bEnableLightBuildNotify)
	{
		return;
	}
	FSlackIncomingWebhook webhook;
	webhook.Channel = USlackNotifySettings::Get()->ChannelID;
	webhook.Username = USlackNotifySettings::Get()->Username;
	webhook.IconEmoji = USlackNotifySettings::Get()->IconEmoji;
	webhook.WebhookUrl = USlackNotifySettings::Get()->WebhookUrl;
	FSlackMessage message;

	message.MessageText = FString("LightBuild Failed.");
	ISlackIntegrationsModule::Get().GetIncomingWebhookInterface().SendMessage(webhook, message);
}

void FSlackNotifyPluginModule::StartupModule()
{
	OnLightBuildSucceededHandle = FEditorDelegates::OnLightingBuildSucceeded.AddRaw(this, &FSlackNotifyPluginModule::OnLightBuildSucceeded);
	OnLightBuildFailedHandle = FEditorDelegates::OnLightingBuildFailed.AddRaw(this, &FSlackNotifyPluginModule::OnLightBuildFailed);

	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings("Project", "SlackNotify", "SlackNotifySettings",
			LOCTEXT("SettingsName", "SlackNotify Settings"),
			LOCTEXT("SettingsDescription", "Configure my settings"),
			GetMutableDefault<USlackNotifySettings>()
		);
	}
}

void FSlackNotifyPluginModule::ShutdownModule()
{
	FEditorDelegates::OnLightingBuildSucceeded.Remove(OnLightBuildSucceededHandle);
	FEditorDelegates::OnLightingBuildFailed.Remove(OnLightBuildFailedHandle);

	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "SlackNotify", "SlackNotifySettings");
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSlackNotifyPluginModule, SlackNotifyPlugin)