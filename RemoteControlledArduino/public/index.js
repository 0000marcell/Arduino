function test(){
	alert('testing!');
	$.ajax({
		type: "POST",
		url: "/control-led",
		// The key needs to match your method's input parameter (case-sensitive).
		data: JSON.stringify({ msg: 'testing' }),
		contentType: "application/json; charset=utf-8",
		dataType: "json",
		success: function(data){alert(data);},
		failure: function(errMsg) {
			alert(errMsg);
		}
	});
}
