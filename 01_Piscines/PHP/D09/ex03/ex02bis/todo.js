
$(document).ready(() => {
	loadToDo();
	handleEvent();
});

$(window).on("unload", () => {
	let todo = $("#ft_list").children();
    let newCookie = [];
    for (let i = 0, c = todo.length; i < c; i++)
        newCookie.unshift(todo[i].innerHTML);
    document.cookie = JSON.stringify(newCookie);
});

function loadToDo() {
	let cookie = document.cookie;
	if (cookie) {
		let toDoList = JSON.parse(cookie);
		toDoList.forEach((ele) => {
			addToDo(ele);
		})
	}
}

function handleEvent() {
	$("#new").click(newToDo);
}

function newToDo() {
	let toDo = prompt("What do you want to do ?", "");
	if (toDo != null & toDo != "")
		addToDo(toDo);
}

function addToDo(toDo) {
	$("#ft_list").prepend('<div>' + toDo + '</div>');
	$("#ft_list div:first-child").click(delToDo);
}

function delToDo() {
	if (confirm("Do you really want to delete it ?"))
		this.remove();
}