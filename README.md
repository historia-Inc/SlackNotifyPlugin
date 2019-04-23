# SlackNotifyPlugin
UE4からSlackへライトビルド完了などの通知を送るプラグインです。  
## プラグインの追加
SlackNotifyPluginを任意のPluginsフォルダにコピーして下さい。  
プラグインの一覧からSlackNotifyPluginのEnableにチェックが入っていれば有効です。
## 各種設定
ProjectSettingsのSlackNotifySettingsで設定ができます。  
- Enable Light Build Notify
ライトビルド完了を通知する機能の有効無効の切り替えができます。
- Webhook Url
SlackAppのIncomingWebHooksで設定した際に表示されるWebhook URLを入力してください。
- Channel ID
送信先チャンネルのチャンネルIDを入力してください。
- Username
Slackのメッセージ投稿者名です。
- Icon Emoji
Slackの投稿のアイコンです