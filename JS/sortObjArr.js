function sortObjArr(objArr, key){
  return objArr.sort((a, b) => a[key] - b[key])
}

sortObjArr([
  {
    name: "John",
    age: 34
  },
  {
    name: "Johny",
    age: 23
  },
  {
    name: "Dan",
    age: 18
  }
], "age")
