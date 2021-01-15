ALTER TABLE Species
	ADD CONSTRAINT ani CHECK (animalCount >= 0);
ALTER TABLE Members
	ADD CONSTRAINT b CHECK (expirationDate > joinDate);
ALTER TABLE Keepers
	ADD CONSTRAINT c CHECK (keeperLevel = NULL) AND (keeperSalary = NULL)
		OR (keeperLevel != NULL) AND (keeperSalary != NULL);
