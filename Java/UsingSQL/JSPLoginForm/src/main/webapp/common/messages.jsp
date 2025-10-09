<%-- Error Messages --%>
<c:if test="${not empty errors}">
  <div class="error" id="errorMessages">
    <c:forEach var="error" items="${errors}">
      <img src="<c:url value="/img/iconWarning.gif"/>"
           alt="<fmt:message key="icon.warning"/>" class="icon" />
      <c:out value="${error}"/><br />
    </c:forEach>
  </div>
  <c:remove var="errors"/>
</c:if>

<%-- Success Messages --%>
<c:if test="${not empty successMessages}">
  <div class="message" id="successMessages">
    <c:forEach var="msg" items="${successMessages}">
      <img src="<c:url value="/img/iconInformation.gif"/>"
           alt="<fmt:message key="icon.information"/>" class="icon" />
      <c:out value="${msg}"/><br />
    </c:forEach>
  </div>
  <c:remove var="successMessages" scope="session"/>
</c:if>