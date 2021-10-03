import { getLocaleDateFormat } from '@angular/common';
import { Injectable } from '@angular/core';
import { HttpClient } from "@angular/common/http";
import { concatMap, map } from 'rxjs/operators';
import { NgxCsvParser } from 'ngx-csv-parser';
import { parse, format } from 'date-fns';
import { Availability } from '../models/availability.model';
import { Observable, of } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class CoachDateTimeFetchService {

  availabilities: Array<Availability> = [];   // stores the list of availablity after parsing the csv file
  uniqueCoaches = new Set();                  // stores the unique names of coaches  
  selectedCoaches: Array<string> = [];        // stores the selected names of coaches from the Coach Select page

  constructor(private httpClient: HttpClient, private ngxCsvParser: NgxCsvParser) { 
    this.availabilities = new Array<Availability>();
  }

  /**
   * Fills up the variables like availabilities and uniqueCoaches. 
   ***/
  getCoaches(): Observable<string[]> {
    return new Observable<string[]>(obs => {
      // if we haven't already fetched the csv content do so; otherwise just read from memory
      if(this.availabilities.length == 0) {
        this.fetchData().subscribe(data => {
          const result = this.ngxCsvParser.csvStringToArray(data, ',');
          //console.log("Result: \n", result);
          //result.slice(1).forEach(avail => {
          for(let avail of result.slice(1)) {   // ignore the header
            if(avail) {
              let availability = new Availability();
              availability.name = avail[0];
              availability.availableFrom = this.parseTimeOfTheWeek(avail[1], avail[2], avail[3]);
              availability.availableTo = this.parseTimeOfTheWeek(avail[1], avail[2], avail[4]);
              this.availabilities.push(availability);
    
              // also add the unique coach names
              this.uniqueCoaches.add(availability.name);
            }
          //});
          } 
  
          console.log("DATA LOADED ");
          //return obs.next(this.availabilities); 
          let returnArr : Array<string> = Array.from(this.uniqueCoaches) as Array<string>;//[];
          //for(string uniqAvail of this.uniqueCoaches) returnArr.push(uniqAvail);
          return obs.next((Array.from(this.uniqueCoaches) as Array<string>));  
        });
      }
      else
        //obs.next(this.availabilities);
        obs.next((Array.from(this.uniqueCoaches) as Array<string>));
    });
  }

  /**
   * Gets the availabilities as read from the csv file
   ***/
  getAvailability() : Observable<Availability[]> {
    return new Observable<Availability[]>(obs => { 
      return obs.next(this.availabilities);
    });
  }

  /**
   * Fetches the data from the local file. In case you want to move to online, jsut replace the src with the actual GET url
   ***/
  fetchData(): Observable<string> {
   return this.httpClient.get("assets/data.csv", {responseType: 'text'})
    .pipe(
      map((file: string) => {
          return file;
      }));
  }

  /**
   * Use the date-fns library to parse the datetime
   ***/
  parseTimeOfTheWeek(timezone: string, dayOfWeek: string, time: string) : Date {
    if(!(timezone && dayOfWeek && time))
      return null;

    const gmtTime = timezone.substring(4, 10);
    const formattedTime = gmtTime + ";" + dayOfWeek + ";" + time.replace(/\s/g, "");
    let a = parse(formattedTime, "XXXXX;cccc;h:mmaaa", new Date());
    return a;
  }
}
