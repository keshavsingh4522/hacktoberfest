import { Time } from "@angular/common"

export class Availability {

    constructor() {}
    
    name: string;
    availableFrom: Date;
    availableTo: Date;

    prefab(name: string): Availability {
        let a = new Availability();
        a.name = name;
        return a;
    }
}