function myFunction() {
   var copyText = document.getElementById('myInput');
   if (copyText.value == '') {
      swal('Error Occurred!', 'You mush short an URL before copy 🤓', 'error');
      return;
   }
   copyText.select();
   copyText.setSelectionRange(0, 99999);
   document.execCommand('copy');
   swal('Copied!', `Your shorten link is: ${copyText.value}`, 'success');
}
