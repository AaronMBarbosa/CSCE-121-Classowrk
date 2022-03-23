size_t** create_matrix(size_t rows, size_t cols)
{
	size_t** newArray = new size_t*[rows]; //Create Rows

	for (size_t i = 0; i < rows; ++i)
	{
		newArray[i] = new size_t[cols]; //Create Columns
	}

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t k = 0; k < cols; ++k)
		{
			newArray[i][k] = 0; //Set everything to zero
		}
	}
		
	return newArray;
}

size_t** create_matrix(size_t n)
{
	size_t** newArray = new size_t*[n]; //Create Rows

	for (size_t i = 0; i < n; ++i)
	{
		newArray[i] = new size_t[n]; //Create Columns
	}

	for (size_t i = 0; i < n; ++i)
	{
		for (size_t k = 0; k < n; ++k)
		{
			newArray[i][k] = 0; //Set everything to zero
		}
	}

	//for (int i = 0; i < rows; ++i)
		//delete[] newArray[i];
	//delete[] newArray;

	return newArray;
}