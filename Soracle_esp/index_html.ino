String index_html(){
  return "<html><head><style type='text/css'>"+ index_css() +"</style></head><body><h1>Soracle</h1><hr><div class='content'><h3>現在の太陽光情報<h3><p>バッテリー電圧: "+ powerV +"</p></div></body></html>";
}

String index_css(){
  return "body{background-color: rgb(200, 200, 200); .content{width: 80%}";
}
