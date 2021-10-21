// function to update item from local storage
function update() {
    // update the table
    tbody = document.getElementById('tableBody');
    ourstorage = JSON.parse(localStorage.getItem('itemsJson'));
    str = ''
    if (ourstorage != null)
        ourstorage.forEach((element, index) => {
            str += ` 
        <tr>
            <td scope="row">${index + 1}</th>
            <td>${element[0]}</td>
            <td>${element[1]}</td>
            <td><button class="btn btn-primary" onclick = 'deleted(${index})'> Delete </button></td>
        </tr>
    `
            document.getElementById('title').value = "";
            document.getElementById('description').value = "";
        });
    tbody.innerHTML = str;

    function deleted(itemindex) {
        itemJsonArraystr = localStorage.getItem('itemsJson');
        itemJsonArray = JSON.parse(itemJsonArraystr);
        itemJsonArray.
            localStorage.setItem('itemsJson', JSON.stringify(itemJsonArray));
        update();
    }
    // table updated
}

add = document.getElementById('add');
add.addEventListener('click', () => {
    let tit = document.getElementById('title').value;
    let desc = document.getElementById('description').value;
    if (tit.length == 0 && desc.length == 0) {
        return;
    }
    if (localStorage.getItem('itemsJson') == null) {
        itemJsonArray = [];
        itemJsonArray.push([tit, desc]);
        localStorage.setItem('itemsJson', JSON.stringify(itemJsonArray));
    } else {
        itemJsonArraystr = localStorage.getItem('itemsJson');
        itemJsonArray = JSON.parse(itemJsonArraystr);
        itemJsonArray.push([tit, desc]);
        localStorage.setItem('itemsJson', JSON.stringify(itemJsonArray));
    }

    update();
})

deleted = (items) => {
    itemJsonArraystr = localStorage.getItem('itemsJson');
    itemJsonArray = JSON.parse(itemJsonArraystr);
    itemJsonArray.splice(items, 1);
    localStorage.setItem('itemsJson', JSON.stringify(itemJsonArray));

    update();
}
clearlist = () => {
    localStorage.clear();
    update();
}
update();

// functionality for switching between dark and light modes
var dark = localStorage['darkmodestatus']
if (dark == undefined) {
    localStorage.setItem('darkmodestatus', 'no')
} else if (dark == 'no') {
    darkModeDisabled();
} else if (dark == 'yes') {
    darkModeEnabled();
}

function darkModeEnabled() {
    $('.light-mode').addClass('dark-mode')
    $('.dark-mode').removeClass('light-mode')
    localStorage.setItem('darkmodestatus', 'yes')

}

function darkModeDisabled() {
    $('.dark-mode').addClass('light-mode')
    $('.light-mode').removeClass('dark-mode')
    localStorage.setItem('darkmodestatus', 'no')
}
$('#darkmode').on('click', function () {
    console.log("h")
    if (localStorage['darkmodestatus'] == 'no')
        darkModeEnabled();
    else
        darkModeDisabled();
})