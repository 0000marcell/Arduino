function ajax(msg){
	$.ajax({
		url: '/control-led', 
		type: 'POST', 
		contentType: 'application/json', 
		data: JSON.stringify({msg: msg})
	});
}

function on(){
	ajax('on');
}

function off(){
	ajax('off');
}
