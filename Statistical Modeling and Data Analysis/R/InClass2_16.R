require(mosaic)
gender_discrimination <- openintro::gender_discrimination
tally(~ gender + decision, data = gender_discrimination)