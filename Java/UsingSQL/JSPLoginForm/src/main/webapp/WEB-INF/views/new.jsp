<%@ include file="/common/taglibs.jsp" %>
<html>
<head>
  <title>Address Book Demo :: New Contact</title>
  <link rel="stylesheet" type="text/css" href="${ctx}/css/app/index.css" />
</head>
<body id="new">

  <div class="bd container-fluid">
    <div class="row-fluid">
      <div class="span3"></div>

      <div class="bd span6">
        <h3 class="title"><fmt:message key="page.new_contact.title"/> </h3>

        <form:form commandName="contact" cssClass="form-horizontal">
          <form:errors path="*" cssClass="flash alert alert-danger" />

          <label class="control-label" for="prefix">
            <fmt:message key="page.new_contact.form.prefix"/>
          </label>
          <div class="controls">
            <form:select path="prefix">
              <form:option value="" label="" />
              <form:options items="${prefixes}" />
            </form:select>
            &nbsp;
          </div>

          <label class="control-label" for="firstName">
            <fmt:message key="page.new_contact.form.first_name"/>
          </label>
          <div class="controls">
            <form:input path="firstName" cssClass="span8" />
          </div>

          <label class="control-label required" for="lastName">
            <fmt:message key="page.new_contact.form.last_name"/>
          </label>
          <div class="controls">
            <form:input path="lastName" cssClass="span8" />
          </div>

          <label class="control-label" for="email">
            <fmt:message key="page.new_contact.form.email"/>
          </label>
          <div class="controls">
            <form:input path="email" cssClass="span8" />
          </div>

          <div class="form-actions">
            <input type="submit" class="btn btn-primary" value="<fmt:message key="page.new_contact.button.save"/>" />
            <input type="reset" class="btn" id="btnReset" value="<fmt:message key="page.new_contact.button.reset"/>" />
          </div>
        </form:form>
      </div>

      <div class="span3"></div>
    </div>
  </div>

</body>
</html>