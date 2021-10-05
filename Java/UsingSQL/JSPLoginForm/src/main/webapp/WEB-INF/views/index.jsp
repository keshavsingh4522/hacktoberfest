<%@ include file="/common/taglibs.jsp" %>
<html>
<head>
  <title>Address Book Demo :: Welcome</title>
  <link rel="stylesheet" type="text/css" href="${ctx}/css/app/index.css" />
</head>
<body id="index">
<div class="bd container-fluid">

  <h3>Contact List</h3>

  <table class="table table-striped">
    <thead>
    <tr>
      <th>ID</th>
      <th>First Name</th>
      <th>Last Name</th>
      <th>Email</th>
      <th>Operations</th>
    </tr>
    </thead>
    <tbody>
    <c:forEach items="${contacts}" var="contact">
    <tr>
      <td>${contact.id}</td>
      <td>${contact.firstName}</td>
      <td>${contact.lastName}</td>
      <td>${contact.email}</td>
      <td></td>
    </tr>
    </c:forEach>
    </tbody>
  </table>

</div>
</body>
</html>