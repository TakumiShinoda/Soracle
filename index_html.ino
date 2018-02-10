String index_html(){
  return "<html><head><style type='text/css'>"+ index_css() +"</style></head><body><h1>Solacle</h1><hr><div class='content'><h3>現在の太陽光情報<h3></div></body></html>";
}

String index_css(){
  return "body{background-color: rgb(200, 200, 200); .content{width: 80%}";
}
