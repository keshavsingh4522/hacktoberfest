package com.todc.addressbook.repository;


import com.todc.addressbook.domain.Contact;

import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;


/**
 * @author Tim O'Donnell (tim.odonnell@imperva.com)
 */
public interface ContactRepository extends JpaRepository<Contact, Long> {

    public Contact findById(Long id);

    public List<Contact> findAll();

}
