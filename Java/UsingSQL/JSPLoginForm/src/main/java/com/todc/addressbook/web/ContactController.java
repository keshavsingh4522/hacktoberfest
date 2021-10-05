package com.todc.addressbook.web;


import com.todc.addressbook.domain.Contact;
import com.todc.addressbook.repository.ContactRepository;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.ui.ModelMap;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.WebDataBinder;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;
import org.springframework.web.servlet.view.RedirectView;

import javax.validation.Valid;
import java.util.Collection;
import java.util.List;


/**
 * @author Tim O'Donnell (odonnellt@gmail.com)
 */
@Controller
public class ContactController {

    private static final Logger LOG = LoggerFactory.getLogger(ContactController.class);


    // ----------------------------------------------------- Instance Variables


    @Autowired
    private ContactRepository contactRepo;


    // --------------------------------------------------------------- Mutators


    public ContactRepository getContactRepo() {
        return contactRepo;
    }

    public void setContactRepo(ContactRepository p_contactRepo) {
        contactRepo = p_contactRepo;
    }


    // --------------------------------------------------------- Public Methods


//    @InitBinder
//    protected void initBinder(WebDataBinder binder) {
//        binder.setValidator(new ContactValidator());
//    }


    /**
     * List all contacts.
     *
     * @return ModelAndView
     * @throws Exception
     */
    @RequestMapping(value = "/index", method = RequestMethod.GET)
    public ModelAndView indexAction() throws Exception {
        LOG.debug("start SampleController > indexAction");

        List<Contact> contacts = contactRepo.findAll();

        ModelAndView mav = new ModelAndView("index");
        mav.addObject("contacts", contacts);

        return mav;
    }


    /**
     * Display the New Contact form.
     *
     * @return ModelAndView
     * @throws Exception
     */
    @RequestMapping(value = "/new", method = RequestMethod.GET)
    public ModelAndView newAction() throws Exception {
        LOG.debug("start SampleController > newAction");

        ModelAndView mav = new ModelAndView("new");
        mav.addObject("contact", new Contact());

        return mav;
    }


    /**
     * Create a new contact.
     *
     * @param newContact
     * @param result
     * @param flash
     * @return
     * @throws Exception
     */
    @RequestMapping(value = "/new", method = RequestMethod.POST)
    public String createAction(@Valid Contact newContact, BindingResult result, RedirectAttributes flash) throws Exception {
        if (result.hasErrors()) {
            return "new";
        }

        contactRepo.save(newContact);

        flash.addFlashAttribute("flash", "Success!");

        return "redirect:index";
    }


    @ModelAttribute("prefixes")
    public String[] populatePrefixes() {
        return new String[] {
            "Mr.",
            "Mrs.",
            "Ms."
        };
    }
    
}
