$(document).ready(function() {
    // render select objects using todc-select2
    $("select").select2({
        placeholder: "Select...",
        containerCssClass: "span8",
        minimumResultsForSearch: 10
    });

    // correctly reset select2 object values
    $("form").on('reset', function() {
        $(this).find("select").val("").trigger("change");
    });
});