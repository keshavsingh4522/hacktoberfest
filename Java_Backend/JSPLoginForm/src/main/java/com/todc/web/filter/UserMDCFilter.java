package com.todc.web.filter;


import java.io.IOException;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;

import org.slf4j.MDC;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.security.core.userdetails.UserDetails;


/**
 * @author Tim O'Donnell (odonnellt@gmail.com)
 */
public class UserMDCFilter implements Filter {

    private final String USER_KEY = "username";

    public void destroy() {}

    public void doFilter(ServletRequest request, ServletResponse response,
                         FilterChain chain) throws IOException, ServletException {
        String username = null;

        Authentication auth = SecurityContextHolder.getContext().getAuthentication();
        if (auth != null) {
            Object principal = auth.getPrincipal();
            if (principal instanceof UserDetails) {
                username = ((UserDetails) principal).getUsername();
            } else {
                username = principal.toString();
            }

            MDC.put(USER_KEY, username);
        }

        try {
            chain.doFilter(request, response);
        } finally {
            if (username != null) {
                MDC.remove(USER_KEY);
            }
        }
    }

    public void init(FilterConfig arg0) throws ServletException {}
}
