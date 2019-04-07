    
let ft_list;

window.onload = () => {
	prepareDOM();
	loadToDo(ft_list);
	handleEvent(ft_list);
}

window.onunload = function () {
    let todo = ft_list.children;
    let newCookie = [];
    for (let i = 0; i < todo.length; i++)
        newCookie.unshift(todo[i].innerHTML);
    document.cookie = JSON.stringify(newCookie);
};

function prepareDOM() {
	ft_list = document.getElementById('ft_list');
}

function loadToDo() {
	let cookie = document.cookie;
	if (cookie) {
		let toDoList = JSON.parse(cookie);
		toDoList.forEach((ele) => {
			addToDo(ft_list, ele);
		})
	}
}

function handleEvent() {
	let newBtn = document.getElementById('new');
	newBtn.addEventListener('click', newToDo);
}

function newToDo() {
	let toDo = prompt("What do you want to do ?", "");
	if (toDo != null & toDo != "")
		addToDo(ft_list, toDo);
}

function addToDo(ft_list, toDo) {
	let item = document.createElement("div");
	item.innerHTML = toDo;
	item.addEventListener("click", delToDo);
	ft_list.insertBefore(item, ft_list.firstChild);
}

function delToDo() {
	if (confirm("Do you really want to delete it ?"))
		this.remove();
}