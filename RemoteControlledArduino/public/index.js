function ajax(msg){
	$.ajax({
		url: '/controlar',
		type: 'POST', 
		contentType: 'application/json', 
		data: JSON.stringify({msg: msg})
	});
}

function ligar(){
	alert('ligar');
	ajax("on");
}
 
function desligar(){    
	ajax ("off");
}
