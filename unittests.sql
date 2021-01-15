INSERT INTO CageVisits (cageID)
	('5');
INSERT INTO CageVisits (memberID)
	('1001');

UPDATE Species SET animalCount = -1
	WHERE animalCount = 1;
UPDATE Species SET animalCount = 5
	WHERE animalCount = 2;

UPDATE Members SET expirationDate = '2021-02-02'
	WHERE joinDate = '2020-02-02';
UPDATE Members SET expirationDate = '2010-02-05'
	WHERE joinDate = '2019-02-02';

UPDATE Keepers SET keeperSalary = NULL
	WHERE keeperLevel != NULL;
UPDATE Keepers SET keeperLevel = '5'
	WHERE keeperSalary != NULL;


