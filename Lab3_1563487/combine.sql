BEGIN TRANSACTION ISOLATION LEVEL SERIALIZABLE;

UPDATE Animals
SET speciesID = n.speciesID, cageID = n.cageID
FROM AnimalChanges n
WHERE animalID IN
	(SELECT animalID
	FROM Animals);

INSERT INTO Animals(animalID)
	SELECT DISTINCT animalID
	FROM AnimalChanges
	WHERE animalID NOT IN
		(SELECT animalID
		FROM Animals);

COMMIT;