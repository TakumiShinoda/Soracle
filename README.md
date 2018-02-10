# Soracle システム

### 概要
庭で太陽光発電した電気をバッテリーに蓄えて自分の部屋で夜のライト代わりに置き換えて家の省エネ化を進める。さらに太陽光の強い方向に`ソーラー`パネルを`(クルっと)`回転させて発電の効率化を測る。また発電情報や稼働情報、バッテリーの状態を常に監視して動作させる。

### 構成
* ソーラーパネル 5V 230mA 1.15W x4
* 鉛電池 6V 4Ah
* arduino pro mini => 太陽光測定、サーボの操作、バッテリー残量(電圧)の監視
* esp8266 => arduinoから値を受け取りSPIFFSで保存、webサーバー
