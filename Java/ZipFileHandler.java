package com.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Enumeration;
import java.util.stream.Collectors;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

public class ZipFileHandler {

    public void listZipFileContents(String filePath) throws Exception{
        ZipFile zipFile = null;
        try{
            zipFile = new ZipFile(filePath);
            Enumeration<? extends ZipEntry> enumeration = zipFile.entries();
            while (enumeration.hasMoreElements()){
                ZipEntry zipEntry = enumeration.nextElement();
                System.out.println(zipEntry.getName());
            }
        }
        catch (Exception e){
            System.out.println("Error: "+e);
        }
        finally {
            try {
                if(zipFile != null) {
                    zipFile.close();
                }
            }
            catch (Exception e){
                System.out.println("Error: "+e);
            }
        }
    }

    public void searchAndReadInZipEntity(String searchPath, String zipFilePath){
        ZipFile zipFile = null;

        boolean fileFound = false;

        try {

            zipFile = new ZipFile(zipFilePath);

            Enumeration<? extends ZipEntry> e = zipFile.entries();

            while (e.hasMoreElements()) {

                ZipEntry entry = e.nextElement();

                // get the name of the entry
                String entryName = entry.getName();

                if (entryName.equalsIgnoreCase(searchPath)) {
                    fileFound = true;
                    InputStream inputStream = zipFile.getInputStream(entry);
                    String result = new BufferedReader(new InputStreamReader(inputStream))
                            .lines().collect(Collectors.joining("\n"));
                    System.out.println(result);
                    break;
                }

            }

        }
        catch (IOException ioe) {
            System.out.println("Error opening zip file" + ioe);
        }
        finally {
            try {
                if (zipFile!=null) {
                    zipFile.close();
                }
            }
            catch (IOException ioe) {
                System.out.println("Error while closing zip file" + ioe);
            }
        }

        System.out.println("File found: " + fileFound);

    }
}
