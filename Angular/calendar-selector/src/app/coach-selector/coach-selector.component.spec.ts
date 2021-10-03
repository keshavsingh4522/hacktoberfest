import { ComponentFixture, TestBed } from '@angular/core/testing';

import { CoachSelectorComponent } from './coach-selector.component';

describe('CoachSelectorComponent', () => {
  let component: CoachSelectorComponent;
  let fixture: ComponentFixture<CoachSelectorComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ CoachSelectorComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(CoachSelectorComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
