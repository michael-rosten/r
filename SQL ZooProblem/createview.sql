CREATE VIEW viewComputedCount(speciesID,computedAnimalCount) AS
	SELECT  DISTINCT speciesID, COUNT(speciesID) as computedAnimalCount
	FROM Animals
	GROUP BY speciesID
	HAVING computedAnimalCount > 2;
