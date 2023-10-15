<%@ include file="/common/taglibs.jsp" %>
<!DOCTYPE html>
<html>
<head>
  <title>Address Book Demo :: Login</title>
  <link rel="stylesheet" type="text/css" href="${ctx}/css/app/login.css" />
</head>
<body>

<div class="container-fluid">

  <div class="signin">
    <div class="signin-box">
      <h2 class="form-signin-heading"><fmt:message key="page.login.title" /></h2>

      <c:if test="${param.invalid}">
        <div class="alert alert-error">
          <strong><fmt:message key="page.login.invalid_credentials" /></strong>
        </div>
      </c:if>

      <form accept-charset="UTF-8" action="<c:url value='j_spring_security_check'/>" method="post">
        <fieldset>
          <label for="username"><fmt:message key="page.login.username" /></label>
          <input type="text" class="input-block-level" name="j_username" id="username">
          <label for="passwd"><fmt:message key="page.login.password" /></label>
          <input type="password" class="input-block-level" name="j_password" id="passwd">

          <input type="submit" class="btn btn-primary" value="Sign in">
          <label class="remember">
            <input type="checkbox" name="rememberMe" value="yes">
            <strong class="remember-label"><fmt:message key="page.login.remember" /></strong>
          </label>
        </fieldset>
      </form>
    </div>
  </div>

</div>

<script type="text/javascript">
  $(function() {
    $("#username").focus();
  });
</script>

</body>
</html>