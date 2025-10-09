<%@ taglib prefix="decorator" uri="http://www.opensymphony.com/sitemesh/decorator" %>
<%@ include file="/common/taglibs.jsp"%>
<html>
<head>
  <title><decorator:title default="Address Book Demo" /></title>

  <link rel="stylesheet" type="text/css" href="${ctx}/css/vendor/bootstrap.css" />
  <link rel="stylesheet" type="text/css" href="${ctx}/css/vendor/todc-bootstrap.css" />
  <link rel="stylesheet" type="text/css" href="${ctx}/css/vendor/todc-select2.css" />
  <link rel="stylesheet" type="text/css" href="${ctx}/css/app/global.css" />

  <script type="text/javascript" src="${ctx}/js/vendor/jquery-1.9.1-min.js"></script>
  <script type="text/javascript" src="${ctx}/js/vendor/select2.js"></script>
  <script type="text/javascript" src="${ctx}/js/app/app.js"></script>

  <decorator:head/>
</head>
<body<decorator:getProperty property="body.id" writeEntireProperty="true"/><decorator:getProperty property="body.class" writeEntireProperty="true"/>>

<div class="navbar navbar-inverse navbar-fixed-top">
  <div class="navbar-inner">
    <div class="container-fluid">
      <a class="brand"><fmt:message key="app.name" /></a>
      <div class="nav-collapse collapse">
        <ul class="nav pull-right">
          <li>
            <a class="logged-in-user">
              <sec:authorize access="isAuthenticated()">
                <sec:authentication property="principal.username" />
              </sec:authorize>
            </a>
          </li>
          <li class="divider-vertical"></li>
          <li>
            <sec:authorize access="isAuthenticated()">
              <a href="<c:url value="/logout"/>"><fmt:message key="topbar.logout"/></a>
            </sec:authorize>
            <sec:authorize access="isAnonymous()">
              <a href="<c:url value="/login"/>"><fmt:message key="topbar.login"/></a>
            </sec:authorize>
          </li>
        </ul>
      </div>
    </div>
  </div>
</div>

<decorator:body />

<div class="ft">
  <span class="copyright"><fmt:message key="app.copyright"/></span>
  <span class="app"><fmt:message key="app.name"/> (build <fmt:message key="app.buildNumber"/>)</span>
</div>

</body>
</html>
