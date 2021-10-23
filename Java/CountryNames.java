import java.util.Arrays;
import java.util.List;
import java.util.Locale;

public class CountryNames {

	/**
	 * Using Locale fetched all ISO Countries name<br>
	 * with the 2 letter country codes<br>
	 * defined in ISO 3166.
	 */
	public static void main(String[] args) {

		List<String> countries = Arrays.asList(Locale.getISOCountries());

		for (int i = 0; i < countries.size(); i++) {

			String country = countries.get(i);
			Locale locale = new Locale("en", country);

			// Fetching country name
			String countryName = locale.getDisplayCountry();

			// Fetching 2 letter code
			String countryCode = locale.getCountry();

			// Printing the country name and 2 letter code on the console
			System.out.println(countryName + " (" + countryCode + ")");

		}

	}
}
