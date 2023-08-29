let datalength = 0;
var headerData;
var formOpen = false;
var fileName;


function tableSearch() {
    let input, filter, table, tr, td, txtValue;

    //Intialising Variables
    input = document.getElementById("myInput");
    filter = input.value.toUpperCase();
    table = document.getElementById("myTable");
    tr = table.getElementsByClassName("body");
    for (let i = 0; i < tr.length; i++) {
        td = tr[i].getElementsByTagName("td")[0];
        if (td) {
            txtValue = td.textContent || td.innerText;
            if (txtValue.toUpperCase().indexOf(filter) > -1) {
                tr[i].style.display = "";
            } else {
                tr[i].style.display = "none";
            }
        }
    }

}

function Upload() {
    var fileUpload = document.getElementById("fileUpload");
        var reader = new FileReader();
        reader.onload = function (e) {
          var table = document.createElement("table");
          table.setAttribute("id", "myTable")
          var rows = e.target.result.split("\n");
          for (var i = 0; i < rows.length; i++) {
            var cells = rows[i].split(",");
            if(datalength == 0){
              datalength = cells.length;
              headerData = cells;
            }
            if (cells.length > 1) {
              var row = table.insertRow(-1);
              if(i == 0){
                row.classList.add("head");
              }else{
                row.classList.add("body");
              }
              for (var j = 0; j < cells.length; j++) {
                var cell = row.insertCell(-1);
                cell.innerHTML = cells[j];
              }
            }
          }
          var TableDiv = document.getElementById("TableDiv");
          TableDiv.innerHTML = "";
          TableDiv.appendChild(table);
        }
        reader.readAsText(fileUpload.files[0]);
  }

function ToggleForm() {
  if (!formOpen) {

    formOpen = true;
    var form = document.createElement("form");
    form.setAttribute("method", "post");
    form.setAttribute("action", "submit.php");

    for (let i = 0; i < datalength; i++) {
      var formCreate = document.createElement("input");
      formCreate.setAttribute("type", "text");
      formCreate.setAttribute("placeholder", headerData[i]);
      formCreate.classList.add("dynamicForm");
      form.append(formCreate);
    }

    var formButton = document.createElement("input");
    formButton.setAttribute("type", "button");
    formButton.setAttribute("value", "Add Item");
    formButton.setAttribute("onclick", "AddData()");
    form.append(formButton);

    document.getElementById("FormDiv").appendChild(form);
  }else{
    formOpen = false;
    document.getElementById("FormDiv").innerHTML = "";
  }
}

function AddData() {

  var formInfo = document.getElementsByClassName("dynamicForm");
  alert(formInfo[0].value);
  alert(formInfo[1].value);

  var table = document.getElementById("myTable");
  var row = table.insertRow(-1);
  row.classList.add("body");
  for (var i = 0; i < datalength; i++) {
    var cell = row.insertCell(-1);
    cell.innerHTML = formInfo[i].value;
  }
  var TableDiv = document.getElementById("TableDiv");
  TableDiv.innerHTML = "";
  TableDiv.appendChild(table);
}