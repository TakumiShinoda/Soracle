# Soracle システム

### 概要
庭で太陽光発電した電気をバッテリーに蓄えて自分の部屋の夜のライトに置き換えて家の省エネ化を進める。さらに太陽光の強い方向に`ソーラー`パネルを`(クルっと)`回転させて発電の効率化を測る。また発電情報や稼働情報、バッテリーの状態を常に監視して動作させる。

### 構成
* ソーラーパネル 5V 230mA 1.15W x4(並列(直列x2)x2)
* 鉛電池 6V 4Ah
* arduino pro mini => 太陽光測定、サーボの操作、バッテリー残量(電圧)の監視
* esp8266 => arduinoから値を受け取りSPIFFSで保存、自宅sqlサーバー
* digispark(attiny85) => 電源の管理

### サーバー構成
-- サーバリポジトリ=> https://github.com/TakumiShinoda/Soracle-LocalSerevr
* cakePHP
* apache2
* mysql3

### 測定レポート
* 12V LEDモジュールx4、arduino pro mini、esp8266動作時の消費電流 => 約130mA

### 補足情報
* arduino pro miniのbpsが設定の2倍になってしまう

### 課題点
* esp8266の消費電力問題（ソフト面）
* 緊急モードの実装（屋内から有線で操作）
